#ifndef CHARTTRACER_H
#define CHARTTRACER_H

#include "Array1DTracer.h"

class ChartTracer : public BaseArray1DTracer {
public:
    ChartTracer(const string &title = "", const string &className = "ChartTracer") : BaseArray1DTracer(title,
                                                                                                       className) {
    }

    void chart(const ChartTracer &chartTracer) {
        command("chart", {chartTracer.key});
    }
};

#endif
