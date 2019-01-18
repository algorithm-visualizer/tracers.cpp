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
    graphTracer.set(array);
    return 0;
}
