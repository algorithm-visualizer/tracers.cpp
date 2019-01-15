#ifndef CPP_GRAPHTRACER_H
#define CPP_GRAPHTRACER_H

#include "Tracer.h"

class GraphTracer : Tracer {
public:
    GraphTracer(string title = "");

    GraphTracer set(json array2d);

    GraphTracer set();

    GraphTracer reset();

    GraphTracer delay();

    GraphTracer directed(json isDirected);

    GraphTracer directed();

    GraphTracer weighted(json isWeighted);

    GraphTracer weighted();

    GraphTracer addNode(json id, json weight, json x, json y, json visitedCount, json selectedCount);

    GraphTracer addNode(json id, json weight, json x, json y, json visitedCount);

    GraphTracer addNode(json id, json weight, json x, json y);

    GraphTracer addNode(json id, json weight, json x);

    GraphTracer addNode(json id, json weight);

    GraphTracer addNode(json id);

    GraphTracer updateNode(json id, json weight, json x, json y, json visitedCount, json selectedCount);

    GraphTracer updateNode(json id, json weight, json x, json y, json visitedCount);

    GraphTracer updateNode(json id, json weight, json x, json y);

    GraphTracer updateNode(json id, json weight, json x);

    GraphTracer updateNode(json id, json weight);

    GraphTracer updateNode(json id);

    GraphTracer removeNode(json id);

    GraphTracer addEdge(json source, json target, json weight, json visitedCount, json selectedCount);

    GraphTracer addEdge(json source, json target, json weight, json visitedCount);

    GraphTracer addEdge(json source, json target, json weight);

    GraphTracer addEdge(json source, json target);

    GraphTracer updateEdge(json source, json target, json weight, json visitedCount, json selectedCount);

    GraphTracer updateEdge(json source, json target, json weight, json visitedCount);

    GraphTracer updateEdge(json source, json target, json weight);

    GraphTracer updateEdge(json source, json target);

    GraphTracer removeEdge(json source, json target);

    GraphTracer layoutCircle();

    GraphTracer layoutTree(json root, json sorted);

    GraphTracer layoutTree(json root);

    GraphTracer layoutTree();

    GraphTracer layoutRandom();

    GraphTracer visit(json target, json source, json weight);

    GraphTracer visit(json target, json source);

    GraphTracer visit(json target);

    GraphTracer leave(json target, json source, json weight);

    GraphTracer leave(json target, json source);

    GraphTracer leave(json target);

    GraphTracer select(json target, json source);

    GraphTracer select(json target);

    GraphTracer deselect(json target, json source);

    GraphTracer deselect(json target);

    GraphTracer log(json logTracer);
};

#endif
