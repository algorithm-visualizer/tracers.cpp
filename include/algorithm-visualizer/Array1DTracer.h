#ifndef ARRAY1DTRACER_H
#define ARRAY1DTRACER_H

#include "BaseArray1DTracer.h"
#include "ChartTracer.h"

class Array1DTracer : public BaseArray1DTracer {
public:
    Array1DTracer(const string &title = "", const string &className = "Array1DTracer") : BaseArray1DTracer(title,
                                                                                                           className) {
    }

    void chart(const ChartTracer &chartTracer) {
        command("chart", {chartTracer.key});
    }
};

#endif
