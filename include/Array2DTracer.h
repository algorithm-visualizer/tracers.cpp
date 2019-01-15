#ifndef CPP_ARRAY2DTRACER_H
#define CPP_ARRAY2DTRACER_H

#include "Tracer.h"

class Array2DTracer : Tracer {
public:
    Array2DTracer(string title = "") : Tracer("Array2DTracer", title) {
    }

    Array2DTracer set(json array2d) {
        addTrace(key, "set", json::array({array2d}));
        return *this;
    }

    Array2DTracer set() {
        addTrace(key, "set", json::array({}));
        return *this;
    }

    Array2DTracer reset() {
        addTrace(key, "reset", json::array({}));
        return *this;
    }

    Array2DTracer delay() {
        addTrace(key, "delay", json::array({}));
        return *this;
    }

    Array2DTracer patch(json x, json y, json v) {
        addTrace(key, "patch", json::array({x, y, v}));
        return *this;
    }

    Array2DTracer depatch(json x, json y) {
        addTrace(key, "depatch", json::array({x, y}));
        return *this;
    }

    Array2DTracer select(json x, json y) {
        addTrace(key, "select", json::array({x, y}));
        return *this;
    }

    Array2DTracer select(json sx, json sy, json ex, json ey) {
        addTrace(key, "select", json::array({sx, sy, ex, ey}));
        return *this;
    }

    Array2DTracer selectRow(json x, json sy, json ey) {
        addTrace(key, "selectRow", json::array({x, sy, ey}));
        return *this;
    }

    Array2DTracer selectCol(json y, json sx, json ex) {
        addTrace(key, "selectCol", json::array({y, sx, ex}));
        return *this;
    }

    Array2DTracer deselect(json x, json y) {
        addTrace(key, "deselect", json::array({x, y}));
        return *this;
    }

    Array2DTracer deselect(json sx, json sy, json ex, json ey) {
        addTrace(key, "deselect", json::array({sx, sy, ex, ey}));
        return *this;
    }

    Array2DTracer deselectRow(json x, json sy, json ey) {
        addTrace(key, "deselectRow", json::array({x, sy, ey}));
        return *this;
    }

    Array2DTracer deselectCol(json y, json sx, json ex) {
        addTrace(key, "deselectCol", json::array({y, sx, ex}));
        return *this;
    }
};

#endif
