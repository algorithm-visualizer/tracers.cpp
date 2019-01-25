#ifndef CPP_TRACER_H
#define CPP_TRACER_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <nlohmann/json.hpp>
#include <curl/curl.h>

#define MAX_TRACES 1000000
#define MAX_TRACERS 100

class Tracer {
protected:
    using string = std::string;
    using json = nlohmann::json;

private:
    static int tracerCount;
    static json traces;

    static string addTracer(string className, string title) {
        string key = std::to_string(tracerCount++) + "-" + className + "-" + title;
        string method = "construct";
        addTrace(key, method, json::array({className, title}));
        return key;
    }

protected:
    static void addTrace(string tracerKey, string method, json args) {
        traces.push_back({
                                 {"tracerKey", tracerKey},
                                 {"method",    method},
                                 {"args",      args},
                         });
        if (traces.size() > MAX_TRACES) throw std::overflow_error("Traces Limit Exceeded");
        if (tracerCount > MAX_TRACERS) throw std::overflow_error("Tracers Limit Exceeded");
    }

    Tracer(string className, string title) {
        if (title.empty()) title = className;
        key = addTracer(className, title);
    }

public:
    string key;

    static size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string *data) {
        data->append((char *) ptr, size * nmemb);
        return size * nmemb;
    }

    static void onExit() {
        string content = traces.dump();
        if (std::getenv("ALGORITHM_VISUALIZER")) {
            std::ofstream fout("traces.json");
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

int Tracer::tracerCount = 0;
nlohmann::json Tracer::traces = json::array();

int init() {
    atexit(Tracer::onExit);
    return 0;
}

int _ = init();

#endif //CPP_TRACER_H
