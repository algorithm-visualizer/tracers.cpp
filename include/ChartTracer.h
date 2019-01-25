#ifndef CPP_CHARTTRACER_H
#define CPP_CHARTTRACER_H

#include "Tracer.h"

class ChartTracer : public Tracer {
public:
    ChartTracer(string title = "") : Tracer("ChartTracer", title) {
    }

    ChartTracer set(json array1d) {
        addTrace(key, "set", json::array({array1d}));
        return *this;
    }

    ChartTracer set() {
        addTrace(key, "set", json::array({}));
        return *this;
    }

    ChartTracer reset() {
        addTrace(key, "reset", json::array({}));
        return *this;
    }

    ChartTracer delay() {
        addTrace(key, "delay", json::array({}));
        return *this;
    }

    ChartTracer patch(json x, json v) {
        addTrace(key, "patch", json::array({x, v}));
        return *this;
    }

    ChartTracer depatch(json x) {
        addTrace(key, "depatch", json::array({x}));
        return *this;
    }

    ChartTracer select(json x) {
        addTrace(key, "select", json::array({x}));
        return *this;
    }

    ChartTracer select(json sx, json ex) {
        addTrace(key, "select", json::array({sx, ex}));
        return *this;
    }

    ChartTracer deselect(json x) {
        addTrace(key, "deselect", json::array({x}));
        return *this;
    }

    ChartTracer deselect(json sx, json ex) {
        addTrace(key, "deselect", json::array({sx, ex}));
        return *this;
    }

    ChartTracer chart(ChartTracer chartTracer) {
        addTrace(key, "chart", json::array({chartTracer.key}));
        return *this;
    }
};

#endif
