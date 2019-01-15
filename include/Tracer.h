#ifndef CPP_TRACER_H
#define CPP_TRACER_H

#include <string>
#include <fstream>
#include <cstdlib>
#include <nlohmann/json.hpp>

class Tracer {
protected:
    using string = std::string;
    using json = nlohmann::json;

private:
    static int tracerCount;
    static json traces;

    static const long maxTraces;
    static const long maxTracers;

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
        if (traces.size() > maxTraces) throw std::overflow_error("Traces Limit Exceeded");
        if (tracerCount > maxTracers) throw std::overflow_error("Tracers Limit Exceeded");
    }

    string key;

    Tracer(string className, string title) {
        if (title.empty()) title = className;
        key = addTracer(className, title);
    }

public:
    static void onExit() {
        std::ofstream fout("traces.json");
        fout << traces.dump();
        fout.close();
    }
};

int Tracer::tracerCount = 0;
nlohmann::json Tracer::traces = json::array();

const long Tracer::maxTraces = std::stol(getenv("MAX_TRACES"));
const long Tracer::maxTracers = std::stol(getenv("MAX_TRACERS"));

int init() {
    atexit(Tracer::onExit);
    return 0;
}

int _ = init();

#endif //CPP_TRACER_H
