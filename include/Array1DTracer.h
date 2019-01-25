#ifndef CPP_ARRAY1DTRACER_H
#define CPP_ARRAY1DTRACER_H

#include "Tracer.h"
#include "ChartTracer.h"

class Array1DTracer : public Tracer {
public:
    Array1DTracer(string title = "") : Tracer("Array1DTracer", title) {
    }

    Array1DTracer set(json array1d) {
        addTrace(key, "set", {array1d});
        return *this;
    }

    Array1DTracer set() {
        addTrace(key, "set", {});
        return *this;
    }

    Array1DTracer reset() {
        addTrace(key, "reset", {});
        return *this;
    }

    Array1DTracer delay() {
        addTrace(key, "delay", {});
        return *this;
    }

    Array1DTracer patch(json x, json v) {
        addTrace(key, "patch", {x, v});
        return *this;
    }

    Array1DTracer depatch(json x) {
        addTrace(key, "depatch", {x});
        return *this;
    }

    Array1DTracer select(json x) {
        addTrace(key, "select", {x});
        return *this;
    }

    Array1DTracer select(json sx, json ex) {
        addTrace(key, "select", {sx, ex});
        return *this;
    }

    Array1DTracer deselect(json x) {
        addTrace(key, "deselect", {x});
        return *this;
    }

    Array1DTracer deselect(json sx, json ex) {
        addTrace(key, "deselect", {sx, ex});
        return *this;
    }

    Array1DTracer chart(ChartTracer chartTracer) {
        addTrace(key, "chart", {chartTracer.key});
        return *this;
    }
};

#endif
