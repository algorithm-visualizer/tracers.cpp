#include <string>
#include <iostream>
#include "GraphTracer.h"
#include "Randomize.h"

#define N 5

using namespace std;

int main() {
    int array[N][N];
    Randomize::Graph<int>(N, 1, *(new Randomize::Integer(1, 9))).weighted().directed(false).fill(&array[0][0]);
    GraphTracer graphTracer;
    LogTracer logTracer;
    graphTracer.set(array);
    graphTracer.log(logTracer);
    graphTracer.visit(1, 0);
    graphTracer.visit(1, 2);
    return 0;
}
