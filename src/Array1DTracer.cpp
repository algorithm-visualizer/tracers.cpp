#include "Array1DTracer.h"

Array1DTracer::Array1DTracer(string title) : Tracer("Array1DTracer", title) {
}

Array1DTracer Array1DTracer::set(json array1d) {
    addTrace(key, "set", json::array({array1d}));
    return *this;
}

Array1DTracer Array1DTracer::set() {
    addTrace(key, "set", json::array({}));
    return *this;
}

Array1DTracer Array1DTracer::reset() {
    addTrace(key, "reset", json::array({}));
    return *this;
}

Array1DTracer Array1DTracer::delay() {
    addTrace(key, "delay", json::array({}));
    return *this;
}

Array1DTracer Array1DTracer::patch(json x, json v) {
    addTrace(key, "patch", json::array({x, v}));
    return *this;
}

Array1DTracer Array1DTracer::depatch(json x) {
    addTrace(key, "depatch", json::array({x}));
    return *this;
}

Array1DTracer Array1DTracer::select(json x) {
    addTrace(key, "select", json::array({x}));
    return *this;
}

Array1DTracer Array1DTracer::select(json sx, json ex) {
    addTrace(key, "select", json::array({sx, ex}));
    return *this;
}

Array1DTracer Array1DTracer::deselect(json x) {
    addTrace(key, "deselect", json::array({x}));
    return *this;
}

Array1DTracer Array1DTracer::deselect(json sx, json ex) {
    addTrace(key, "deselect", json::array({sx, ex}));
    return *this;
}

Array1DTracer Array1DTracer::chart(json chartTracer) {
    addTrace(key, "chart", json::array({chartTracer}));
    return *this;
}
