#ifndef CPP_GRAPHTRACER_H
#define CPP_GRAPHTRACER_H

#include "Tracer.h"
#include "LogTracer.h"

class GraphTracer : public Tracer {
public:
    GraphTracer(string title = "") : Tracer("GraphTracer", title) {
    }

    GraphTracer set(json array2d) {
        addTrace(key, "set", {array2d});
        return *this;
    }

    GraphTracer set() {
        addTrace(key, "set", {});
        return *this;
    }

    GraphTracer reset() {
        addTrace(key, "reset", {});
        return *this;
    }

    GraphTracer delay() {
        addTrace(key, "delay", {});
        return *this;
    }

    GraphTracer directed(json isDirected) {
        addTrace(key, "directed", {isDirected});
        return *this;
    }

    GraphTracer directed() {
        addTrace(key, "directed", {});
        return *this;
    }

    GraphTracer weighted(json isWeighted) {
        addTrace(key, "weighted", {isWeighted});
        return *this;
    }

    GraphTracer weighted() {
        addTrace(key, "weighted", {});
        return *this;
    }

    GraphTracer addNode(json id, json weight, json x, json y, json visitedCount, json selectedCount) {
        addTrace(key, "addNode", {id, weight, x, y, visitedCount, selectedCount});
        return *this;
    }

    GraphTracer addNode(json id, json weight, json x, json y, json visitedCount) {
        addTrace(key, "addNode", {id, weight, x, y, visitedCount});
        return *this;
    }

    GraphTracer addNode(json id, json weight, json x, json y) {
        addTrace(key, "addNode", {id, weight, x, y});
        return *this;
    }

    GraphTracer addNode(json id, json weight, json x) {
        addTrace(key, "addNode", {id, weight, x});
        return *this;
    }

    GraphTracer addNode(json id, json weight) {
        addTrace(key, "addNode", {id, weight});
        return *this;
    }

    GraphTracer addNode(json id) {
        addTrace(key, "addNode", {id});
        return *this;
    }

    GraphTracer updateNode(json id, json weight, json x, json y, json visitedCount, json selectedCount) {
        addTrace(key, "updateNode", {id, weight, x, y, visitedCount, selectedCount});
        return *this;
    }

    GraphTracer updateNode(json id, json weight, json x, json y, json visitedCount) {
        addTrace(key, "updateNode", {id, weight, x, y, visitedCount});
        return *this;
    }

    GraphTracer updateNode(json id, json weight, json x, json y) {
        addTrace(key, "updateNode", {id, weight, x, y});
        return *this;
    }

    GraphTracer updateNode(json id, json weight, json x) {
        addTrace(key, "updateNode", {id, weight, x});
        return *this;
    }

    GraphTracer updateNode(json id, json weight) {
        addTrace(key, "updateNode", {id, weight});
        return *this;
    }

    GraphTracer updateNode(json id) {
        addTrace(key, "updateNode", {id});
        return *this;
    }

    GraphTracer removeNode(json id) {
        addTrace(key, "removeNode", {id});
        return *this;
    }

    GraphTracer addEdge(json source, json target, json weight, json visitedCount, json selectedCount) {
        addTrace(key, "addEdge", {source, target, weight, visitedCount, selectedCount});
        return *this;
    }

    GraphTracer addEdge(json source, json target, json weight, json visitedCount) {
        addTrace(key, "addEdge", {source, target, weight, visitedCount});
        return *this;
    }

    GraphTracer addEdge(json source, json target, json weight) {
        addTrace(key, "addEdge", {source, target, weight});
        return *this;
    }

    GraphTracer addEdge(json source, json target) {
        addTrace(key, "addEdge", {source, target});
        return *this;
    }

    GraphTracer updateEdge(json source, json target, json weight, json visitedCount, json selectedCount) {
        addTrace(key, "updateEdge", {source, target, weight, visitedCount, selectedCount});
        return *this;
    }

    GraphTracer updateEdge(json source, json target, json weight, json visitedCount) {
        addTrace(key, "updateEdge", {source, target, weight, visitedCount});
        return *this;
    }

    GraphTracer updateEdge(json source, json target, json weight) {
        addTrace(key, "updateEdge", {source, target, weight});
        return *this;
    }

    GraphTracer updateEdge(json source, json target) {
        addTrace(key, "updateEdge", {source, target});
        return *this;
    }

    GraphTracer removeEdge(json source, json target) {
        addTrace(key, "removeEdge", {source, target});
        return *this;
    }

    GraphTracer layoutCircle() {
        addTrace(key, "layoutCircle", {});
        return *this;
    }

    GraphTracer layoutTree(json root, json sorted) {
        addTrace(key, "layoutTree", {root, sorted});
        return *this;
    }

    GraphTracer layoutTree(json root) {
        addTrace(key, "layoutTree", {root});
        return *this;
    }

    GraphTracer layoutTree() {
        addTrace(key, "layoutTree", {});
        return *this;
    }

    GraphTracer layoutRandom() {
        addTrace(key, "layoutRandom", {});
        return *this;
    }

    GraphTracer visit(json target, json source, json weight) {
        addTrace(key, "visit", {target, source, weight});
        return *this;
    }

    GraphTracer visit(json target, json source) {
        addTrace(key, "visit", {target, source});
        return *this;
    }

    GraphTracer visit(json target) {
        addTrace(key, "visit", {target});
        return *this;
    }

    GraphTracer leave(json target, json source, json weight) {
        addTrace(key, "leave", {target, source, weight});
        return *this;
    }

    GraphTracer leave(json target, json source) {
        addTrace(key, "leave", {target, source});
        return *this;
    }

    GraphTracer leave(json target) {
        addTrace(key, "leave", {target});
        return *this;
    }

    GraphTracer select(json target, json source) {
        addTrace(key, "select", {target, source});
        return *this;
    }

    GraphTracer select(json target) {
        addTrace(key, "select", {target});
        return *this;
    }

    GraphTracer deselect(json target, json source) {
        addTrace(key, "deselect", {target, source});
        return *this;
    }

    GraphTracer deselect(json target) {
        addTrace(key, "deselect", {target});
        return *this;
    }

    GraphTracer log(LogTracer logTracer) {
        addTrace(key, "log", {logTracer.key});
        return *this;
    }
};

#endif
