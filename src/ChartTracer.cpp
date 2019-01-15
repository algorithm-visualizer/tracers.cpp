#include "ChartTracer.h"

ChartTracer::ChartTracer(string title) : Tracer("ChartTracer", title) {
}

ChartTracer ChartTracer::set(json array1d) {
    addTrace(key, "set", json::array({array1d}));
    return *this;
}

ChartTracer ChartTracer::set() {
    addTrace(key, "set", json::array({}));
    return *this;
}

ChartTracer ChartTracer::reset() {
    addTrace(key, "reset", json::array({}));
    return *this;
}

ChartTracer ChartTracer::delay() {
    addTrace(key, "delay", json::array({}));
    return *this;
}

ChartTracer ChartTracer::patch(json x, json v) {
    addTrace(key, "patch", json::array({x, v}));
    return *this;
}

ChartTracer ChartTracer::depatch(json x) {
    addTrace(key, "depatch", json::array({x}));
    return *this;
}

ChartTracer ChartTracer::select(json x) {
    addTrace(key, "select", json::array({x}));
    return *this;
}

ChartTracer ChartTracer::select(json sx, json ex) {
    addTrace(key, "select", json::array({sx, ex}));
    return *this;
}

ChartTracer ChartTracer::deselect(json x) {
    addTrace(key, "deselect", json::array({x}));
    return *this;
}

ChartTracer ChartTracer::deselect(json sx, json ex) {
    addTrace(key, "deselect", json::array({sx, ex}));
    return *this;
}

ChartTracer ChartTracer::chart(json chartTracer) {
    addTrace(key, "chart", json::array({chartTracer}));
    return *this;
}
