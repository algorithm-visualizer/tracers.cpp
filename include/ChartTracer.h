#ifndef CPP_CHARTTRACER_H
#define CPP_CHARTTRACER_H

#include "Tracer.h"

class ChartTracer : Tracer {
public:
    ChartTracer(string title = "");

    ChartTracer set(json array1d);

    ChartTracer set();

    ChartTracer reset();

    ChartTracer delay();

    ChartTracer patch(json x, json v);

    ChartTracer depatch(json x);

    ChartTracer select(json x);

    ChartTracer select(json sx, json ex);

    ChartTracer deselect(json x);

    ChartTracer deselect(json sx, json ex);

    ChartTracer chart(json chartTracer);
};

#endif
