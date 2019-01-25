#ifndef CPP_LOGTRACER_H
#define CPP_LOGTRACER_H

#include <regex>
#include "Tracer.h"

class LogTracer : public Tracer {
public:
    LogTracer(string title = "") : Tracer("LogTracer", title) {
    }

    LogTracer set(json log) {
        addTrace(key, "set", {log});
        return *this;
    }

    LogTracer set() {
        addTrace(key, "set", {});
        return *this;
    }

    LogTracer reset() {
        addTrace(key, "reset", {});
        return *this;
    }

    LogTracer delay() {
        addTrace(key, "delay", {});
        return *this;
    }

    LogTracer print(json message) {
        addTrace(key, "print", {message});
        return *this;
    }

    LogTracer println(json message) {
        addTrace(key, "println", {message});
        return *this;
    }

    LogTracer printf(string format, ...) {
        arguments traceArgs = {format};

        va_list args;
        va_start(args, format);
        string::const_iterator searchStart(format.cbegin());
        const std::regex exp(
                "(?:[^\\x25]|^)(?:\\x25{2})*\\x25(?:([1-9]\\d*)\\$|\\(([^)]+)\\))?(\\+)?(0|'[^$])?(-)?(\\d+)?(?:\\.(\\d+))?([b-gijostTuvxX])");
        std::smatch match;
        while (std::regex_search(searchStart, format.cend(), match, exp)) {
            char specifier = match.str(8).at(0);
            switch (specifier) {
                case 'b':
                case 'c':
                case 'd':
                case 'i':
                case 'u':
                case 'o':
                case 't':
                case 'x':
                case 'X':
                    traceArgs.push_back(va_arg(args, int));
                    break;
                case 'e':
                case 'f':
                case 'g':
                    traceArgs.push_back(va_arg(args, double));
                    break;
                case 's':
                    traceArgs.push_back(va_arg(args, char *));
                    break;
                case 'T':
                case 'v':
                case 'j':
                    throw std::invalid_argument("Format Not Supported");
                default:
                    break;
            }
            searchStart = match.suffix().first;
        }
        va_end(args);

        addTrace(key, "printf", traceArgs);
        return *this;
    }
};

#endif
