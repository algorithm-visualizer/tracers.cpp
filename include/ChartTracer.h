#ifndef CPP_CHARTTRACER_H
#define CPP_CHARTTRACER_H

#include "Tracer.h"

class ChartTracer : public Tracer {
public:
    ChartTracer(string title = "") : Tracer("ChartTracer", title) {
    }

    ChartTracer set(json array1d) {
        addTrace(key, "set", {array1d});
        return *this;
    }

    ChartTracer set() {
        addTrace(key, "set", {});
        return *this;
    }

    ChartTracer reset() {
        addTrace(key, "reset", {});
        return *this;
    }

    ChartTracer delay() {
        addTrace(key, "delay", {});
        return *this;
    }

    ChartTracer patch(json x, json v) {
        addTrace(key, "patch", {x, v});
        return *this;
    }

    ChartTracer depatch(json x) {
        addTrace(key, "depatch", {x});
        return *this;
    }

    ChartTracer select(json x) {
        addTrace(key, "select", {x});
        return *this;
    }

    ChartTracer select(json sx, json ex) {
        addTrace(key, "select", {sx, ex});
        return *this;
    }

    ChartTracer deselect(json x) {
        addTrace(key, "deselect", {x});
        return *this;
    }

    ChartTracer deselect(json sx, json ex) {
        addTrace(key, "deselect", {sx, ex});
        return *this;
    }

    ChartTracer chart(ChartTracer chartTracer) {
        addTrace(key, "chart", {chartTracer.key});
        return *this;
    }
};

#endif
