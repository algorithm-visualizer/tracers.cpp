#ifndef TRACER_H
#define TRACER_H

#include "Commander.h"

class Tracer : public Commander {
public:
    static void delay(int lineNumber) {
        command(nullptr, "delay", {lineNumber});
    }

    static void delay() {
        command(nullptr, "delay", {});
    }

    Tracer(const string &title = "", const string &className = "Tracer") : Commander(
            title.empty() ? arguments{} : arguments{title},
            className) {
    }

    void set() {
        command("set", {});
    }

    void reset() {
        command("reset", {});
    }
};

#endif
