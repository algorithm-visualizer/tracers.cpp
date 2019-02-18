#ifndef BASEARRAY1DTRACER_H
#define BASEARRAY1DTRACER_H

#include "Array2DTracer.h"

class BaseArray1DTracer : public Array2DTracer {
public:
    BaseArray1DTracer(const string &title = "", const string &className = "BaseArray1DTracer") : Array2DTracer(title,
                                                                                                       className) {
    }

    void set(const json &array1d) {
        command("set", {array1d});
    }

    void patch(int x, const json &v) {
        command("patch", {x, v});
    }

    void patch(int x) {
        command("patch", {x});
    }

    void depatch(int x) {
        command("depatch", {x});
    }

    void select(int sx, int ex) {
        command("select", {sx, ex});
    }

    void select(int x) {
        command("select", {x});
    }

    void deselect(int sx, int ex) {
        command("deselect", {sx, ex});
    }

    void deselect(int x) {
        command("deselect", {x});
    }
};

#endif
