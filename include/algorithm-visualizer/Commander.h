#ifndef COMMANDER_H
#define COMMANDER_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <curl/curl.h>
#include "nlohmann/json.hpp"
#include "Randomize.h"

#define MAX_COMMANDS 1000000
#define MAX_OBJECTS 100

class Commander {
protected:
    using string = std::string;
    using json = nlohmann::json;
    using arguments = std::vector<json>;

private:
    static Randomize::String *keyRandomizer;
    static int objectCount;
    static json commands;

protected:
    static void command(const json &key, const string &method, const arguments &args) {
        commands.push_back({
                                   {"key",    key},
                                   {"method", method},
                                   {"args",   args},
                           });
        if (commands.size() > MAX_COMMANDS) throw std::overflow_error("Too Many Commands");
        if (objectCount > MAX_OBJECTS) throw std::overflow_error("Too Many Objects");
    }

    Commander(const arguments &args, const string &className = "Commander") {
        objectCount++;
        key = keyRandomizer->create();
        command(className, args);
    }

    void command(const string &method, const arguments &args) {
        command(key, method, args);
    }

public:
    string key;

    void destroy() {
        objectCount--;
        command("destroy", {});
    }

    static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data) {
        data->append((char *) ptr, size * nmemb);
        return size * nmemb;
    }

    static void onExit() {
        string content = commands.dump();
        if (std::getenv("ALGORITHM_VISUALIZER")) {
            std::ofstream fout("visualization.json");
            fout << content;
            fout.close();
        } else {
            auto curl = curl_easy_init();
            if (curl) {
                string params = "content=" + content;

                curl_easy_setopt(curl, CURLOPT_URL, "https://algorithm-visualizer.org/api/visualizations");
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());
                curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
                curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);

                string header;
                string response;
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
                curl_easy_setopt(curl, CURLOPT_HEADERDATA, &header);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

                curl_easy_perform(curl);
                long response_code;
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

                curl_easy_cleanup(curl);
                curl = NULL;

                if (response_code == 200) {
#ifdef linux
                    string command = "xdg-open " + response;
#elif _WIN32
                    string command = "start " + response;
#else
                    string command = "open " + response;
#endif
                    system(command.c_str());
                }
            }
        }
    }
};

Randomize::String *Commander::keyRandomizer = new Randomize::String(8, "abcdefghijklmnopqrstuvwxyz0123456789");
int Commander::objectCount = 0;
nlohmann::json Commander::commands = json::array();

int init() {
    atexit(Commander::onExit);
    return 0;
}

int _ = init();

#endif
