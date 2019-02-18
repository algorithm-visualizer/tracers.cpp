#ifndef ARRAY2DTRACER_H
#define ARRAY2DTRACER_H

#include "Tracer.h"

class Array2DTracer : public Tracer {
public:
    Array2DTracer(const string &title = "", const string &className = "Array2DTracer") : Tracer(title, className) {
    }

    void set(const json &array2d) {
        command("set", {array2d});
    }

    void patch(int x, int y, const json &v) {
        command("patch", {x, y, v});
    }

    void patch(int x, int y) {
        command("patch", {x, y});
    }

    void depatch(int x, int y) {
        command("depatch", {x, y});
    }

    void select(int sx, int sy, int ex, int ey) {
        command("select", {sx, sy, ex, ey});
    }

    void select(int x, int y) {
        command("select", {x, y});
    }

    void selectRow(int x, int sy, int ey) {
        command("selectRow", {x, sy, ey});
    }

    void selectCol(int y, int sx, int ex) {
        command("selectCol", {y, sx, ex});
    }

    void deselect(int sx, int sy, int ex, int ey) {
        command("deselect", {sx, sy, ex, ey});
    }

    void deselect(int x, int y) {
        command("deselect", {x, y});
    }

    void deselectRow(int x, int sy, int ey) {
        command("deselectRow", {x, sy, ey});
    }

    void deselectCol(int y, int sx, int ex) {
        command("deselectCol", {y, sx, ex});
    }
};

#endif
