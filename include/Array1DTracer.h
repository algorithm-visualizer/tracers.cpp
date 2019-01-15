#ifndef CPP_ARRAY1DTRACER_H
#define CPP_ARRAY1DTRACER_H

#include "Tracer.h"

class Array1DTracer : Tracer {
public:
    Array1DTracer(string title = "");

    Array1DTracer set(json array1d);

    Array1DTracer set();

    Array1DTracer reset();

    Array1DTracer delay();

    Array1DTracer patch(json x, json v);

    Array1DTracer depatch(json x);

    Array1DTracer select(json x);

    Array1DTracer select(json sx, json ex);

    Array1DTracer deselect(json x);

    Array1DTracer deselect(json sx, json ex);

    Array1DTracer chart(json chartTracer);
};

#endif
