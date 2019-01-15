cmake_minimum_required(VERSION 3.2)
project(tracers)

set(CMAKE_CXX_STANDARD 11)

add_library(tracers Tracer.cpp LogTracer.cpp Array2DTracer.cpp Array1DTracer.cpp ChartTracer.cpp GraphTracer.cpp)

set_target_properties(tracers
    PROPERTIES
    PREFIX ""
)
