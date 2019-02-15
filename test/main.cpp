#include <string>
#include <iostream>
#include <VerticalLayout.h>
#include <HorizontalLayout.h>
#include "Array1DTracer.h"
#include "Array2DTracer.h"
#include "ChartTracer.h"
#include "Tracer.h"
#include "LogTracer.h"
#include "GraphTracer.h"
#include "Randomize.h"

#define N 5

using namespace std;

int main() {
    int array[N][N];
    Randomize::Graph<int>(N, .5).weighted().directed(false).fill(&array[0][0]);
    Array1DTracer array1DTracer("array");
    Array2DTracer array2DTracer("array2d");
    array2DTracer.set(array);
    array2DTracer.patch(0, 0, "aewg");
    ChartTracer chartTracer("chart");
    GraphTracer graphTracer("graph");
    graphTracer.set(array);
    LogTracer logTracer("log");
    array1DTracer.chart(chartTracer);
    graphTracer.log(logTracer);
    Layout::setRoot(VerticalLayout({
                                           array1DTracer,
                                           array2DTracer,
                                           chartTracer,
                                           HorizontalLayout({
                                                                    graphTracer,
                                                                    logTracer
                                                            })
                                   }));
    string a = "aweg";
    char b[] = "cccc";
    logTracer.printf("%s %d\n", b, 1);
    Tracer::delay();
    a += "awebawea";
    logTracer.println(a);
    return 0;
}
