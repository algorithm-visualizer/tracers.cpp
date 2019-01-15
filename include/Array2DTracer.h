#ifndef CPP_ARRAY2DTRACER_H
#define CPP_ARRAY2DTRACER_H

#include "Tracer.h"

class Array2DTracer : Tracer {
public:
    Array2DTracer(string title = "");

    Array2DTracer set(json array2d);

    Array2DTracer set();

    Array2DTracer reset();

    Array2DTracer delay();

    Array2DTracer patch(json x, json y, json v);

    Array2DTracer depatch(json x, json y);

    Array2DTracer select(json x, json y);

    Array2DTracer select(json sx, json sy, json ex, json ey);

    Array2DTracer selectRow(json x, json sy, json ey);

    Array2DTracer selectCol(json y, json sx, json ex);

    Array2DTracer deselect(json x, json y);

    Array2DTracer deselect(json sx, json sy, json ex, json ey);

    Array2DTracer deselectRow(json x, json sy, json ey);

    Array2DTracer deselectCol(json y, json sx, json ex);
};

#endif
