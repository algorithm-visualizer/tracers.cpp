#ifndef CPP_LOGTRACER_H
#define CPP_LOGTRACER_H

#include "Tracer.h"

class LogTracer : Tracer {
public:
    LogTracer(string title = "");

    LogTracer set(json messages);

    LogTracer set();

    LogTracer reset();

    LogTracer delay();

    LogTracer print(json message);
};

#endif
