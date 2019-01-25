#ifndef CPP_ARRAY2DTRACER_H
#define CPP_ARRAY2DTRACER_H

#include "Tracer.h"

class Array2DTracer : public Tracer {
public:
    Array2DTracer(string title = "") : Tracer("Array2DTracer", title) {
    }

    Array2DTracer set(json array2d) {
        addTrace(key, "set", {array2d});
        return *this;
    }

    Array2DTracer set() {
        addTrace(key, "set", {});
        return *this;
    }

    Array2DTracer reset() {
        addTrace(key, "reset", {});
        return *this;
    }

    Array2DTracer delay() {
        addTrace(key, "delay", {});
        return *this;
    }

    Array2DTracer patch(json x, json y, json v) {
        addTrace(key, "patch", {x, y, v});
        return *this;
    }

    Array2DTracer depatch(json x, json y) {
        addTrace(key, "depatch", {x, y});
        return *this;
    }

    Array2DTracer select(json x, json y) {
        addTrace(key, "select", {x, y});
        return *this;
    }

    Array2DTracer select(json sx, json sy, json ex, json ey) {
        addTrace(key, "select", {sx, sy, ex, ey});
        return *this;
    }

    Array2DTracer selectRow(json x, json sy, json ey) {
        addTrace(key, "selectRow", {x, sy, ey});
        return *this;
    }

    Array2DTracer selectCol(json y, json sx, json ex) {
        addTrace(key, "selectCol", {y, sx, ex});
        return *this;
    }

    Array2DTracer deselect(json x, json y) {
        addTrace(key, "deselect", {x, y});
        return *this;
    }

    Array2DTracer deselect(json sx, json sy, json ex, json ey) {
        addTrace(key, "deselect", {sx, sy, ex, ey});
        return *this;
    }

    Array2DTracer deselectRow(json x, json sy, json ey) {
        addTrace(key, "deselectRow", {x, sy, ey});
        return *this;
    }

    Array2DTracer deselectCol(json y, json sx, json ex) {
        addTrace(key, "deselectCol", {y, sx, ex});
        return *this;
    }
};

#endif
