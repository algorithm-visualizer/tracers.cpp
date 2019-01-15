#ifndef CPP_LOGTRACER_H
#define CPP_LOGTRACER_H

#include "Tracer.h"

class LogTracer : Tracer {
public:
    LogTracer(string title = "") : Tracer("LogTracer", title) {
    }

    LogTracer set(json messages) {
        addTrace(key, "set", json::array({messages}));
        return *this;
    }

    LogTracer set() {
        addTrace(key, "set", json::array({}));
        return *this;
    }

    LogTracer reset() {
        addTrace(key, "reset", json::array({}));
        return *this;
    }

    LogTracer delay() {
        addTrace(key, "delay", json::array({}));
        return *this;
    }

    LogTracer print(json message) {
        addTrace(key, "print", json::array({message}));
        return *this;
    }
};

#endif
