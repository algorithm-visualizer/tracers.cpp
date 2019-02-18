#ifndef LOGTRACER_H
#define LOGTRACER_H

#include <stdarg.h>
#include "Tracer.h"

class LogTracer : public Tracer {
public:
    LogTracer(const string &title = "", const string &className = "LogTracer") : Tracer(title, className) {
    }

    void set(const json &log) {
        command("set", {log});
    }

    void print(const json &message) {
        command("print", {message});
    }

    void println(const json &message) {
        command("println", {message});
    }

    void printf(const char *format, ...) {
        arguments traceArgs = {format};

        va_list args;
        va_start(args, format);

        bool percent = false;
        while (*format != '\0') {
            if (*format == '%') {
                percent = !percent;
            } else if (percent) {
                switch (*format) {
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'i':
                    case 'u':
                    case 'o':
                    case 't':
                    case 'x':
                    case 'X':
                        percent = false;
                        traceArgs.push_back(va_arg(args, int));
                        break;
                    case 'e':
                    case 'f':
                    case 'g':
                        percent = false;
                        traceArgs.push_back(va_arg(args, double));
                        break;
                    case 's':
                        percent = false;
                        traceArgs.push_back(va_arg(args, char *));
                        break;
                    case 'T':
                    case 'v':
                    case 'j':
                        throw std::invalid_argument("Format Not Supported");
                    default:
                        break;
                }
            }
            format++;
        }

        va_end(args);

        command("printf", traceArgs);
    }
};

#endif
