#include "LogTracer.h"

LogTracer::LogTracer(string title) : Tracer("LogTracer", title) {
}

LogTracer LogTracer::set(json messages) {
    addTrace(key, "set", json::array({messages}));
    return *this;
}

LogTracer LogTracer::set() {
    addTrace(key, "set", json::array({}));
    return *this;
}

LogTracer LogTracer::reset() {
    addTrace(key, "reset", json::array({}));
    return *this;
}

LogTracer LogTracer::delay() {
    addTrace(key, "delay", json::array({}));
    return *this;
}

LogTracer LogTracer::print(json message) {
    addTrace(key, "print", json::array({message}));
    return *this;
}
