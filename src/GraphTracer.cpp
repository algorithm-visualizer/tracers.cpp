#include "GraphTracer.h"

GraphTracer::GraphTracer(string title) : Tracer("GraphTracer", title) {
}

GraphTracer GraphTracer::set(json array2d) {
    addTrace(key, "set", json::array({array2d}));
    return *this;
}

GraphTracer GraphTracer::set() {
    addTrace(key, "set", json::array({}));
    return *this;
}

GraphTracer GraphTracer::reset() {
    addTrace(key, "reset", json::array({}));
    return *this;
}

GraphTracer GraphTracer::delay() {
    addTrace(key, "delay", json::array({}));
    return *this;
}

GraphTracer GraphTracer::directed(json isDirected) {
    addTrace(key, "directed", json::array({isDirected}));
    return *this;
}

GraphTracer GraphTracer::directed() {
    addTrace(key, "directed", json::array({}));
    return *this;
}

GraphTracer GraphTracer::weighted(json isWeighted) {
    addTrace(key, "weighted", json::array({isWeighted}));
    return *this;
}

GraphTracer GraphTracer::weighted() {
    addTrace(key, "weighted", json::array({}));
    return *this;
}

GraphTracer GraphTracer::addNode(json id, json weight, json x, json y, json visitedCount, json selectedCount) {
    addTrace(key, "addNode", json::array({id, weight, x, y, visitedCount, selectedCount}));
    return *this;
}

GraphTracer GraphTracer::addNode(json id, json weight, json x, json y, json visitedCount) {
    addTrace(key, "addNode", json::array({id, weight, x, y, visitedCount}));
    return *this;
}

GraphTracer GraphTracer::addNode(json id, json weight, json x, json y) {
    addTrace(key, "addNode", json::array({id, weight, x, y}));
    return *this;
}

GraphTracer GraphTracer::addNode(json id, json weight, json x) {
    addTrace(key, "addNode", json::array({id, weight, x}));
    return *this;
}

GraphTracer GraphTracer::addNode(json id, json weight) {
    addTrace(key, "addNode", json::array({id, weight}));
    return *this;
}

GraphTracer GraphTracer::addNode(json id) {
    addTrace(key, "addNode", json::array({id}));
    return *this;
}

GraphTracer GraphTracer::updateNode(json id, json weight, json x, json y, json visitedCount, json selectedCount) {
    addTrace(key, "updateNode", json::array({id, weight, x, y, visitedCount, selectedCount}));
    return *this;
}

GraphTracer GraphTracer::updateNode(json id, json weight, json x, json y, json visitedCount) {
    addTrace(key, "updateNode", json::array({id, weight, x, y, visitedCount}));
    return *this;
}

GraphTracer GraphTracer::updateNode(json id, json weight, json x, json y) {
    addTrace(key, "updateNode", json::array({id, weight, x, y}));
    return *this;
}

GraphTracer GraphTracer::updateNode(json id, json weight, json x) {
    addTrace(key, "updateNode", json::array({id, weight, x}));
    return *this;
}

GraphTracer GraphTracer::updateNode(json id, json weight) {
    addTrace(key, "updateNode", json::array({id, weight}));
    return *this;
}

GraphTracer GraphTracer::updateNode(json id) {
    addTrace(key, "updateNode", json::array({id}));
    return *this;
}

GraphTracer GraphTracer::removeNode(json id) {
    addTrace(key, "removeNode", json::array({id}));
    return *this;
}

GraphTracer GraphTracer::addEdge(json source, json target, json weight, json visitedCount, json selectedCount) {
    addTrace(key, "addEdge", json::array({source, target, weight, visitedCount, selectedCount}));
    return *this;
}

GraphTracer GraphTracer::addEdge(json source, json target, json weight, json visitedCount) {
    addTrace(key, "addEdge", json::array({source, target, weight, visitedCount}));
    return *this;
}

GraphTracer GraphTracer::addEdge(json source, json target, json weight) {
    addTrace(key, "addEdge", json::array({source, target, weight}));
    return *this;
}

GraphTracer GraphTracer::addEdge(json source, json target) {
    addTrace(key, "addEdge", json::array({source, target}));
    return *this;
}

GraphTracer GraphTracer::updateEdge(json source, json target, json weight, json visitedCount, json selectedCount) {
    addTrace(key, "updateEdge", json::array({source, target, weight, visitedCount, selectedCount}));
    return *this;
}

GraphTracer GraphTracer::updateEdge(json source, json target, json weight, json visitedCount) {
    addTrace(key, "updateEdge", json::array({source, target, weight, visitedCount}));
    return *this;
}

GraphTracer GraphTracer::updateEdge(json source, json target, json weight) {
    addTrace(key, "updateEdge", json::array({source, target, weight}));
    return *this;
}

GraphTracer GraphTracer::updateEdge(json source, json target) {
    addTrace(key, "updateEdge", json::array({source, target}));
    return *this;
}

GraphTracer GraphTracer::removeEdge(json source, json target) {
    addTrace(key, "removeEdge", json::array({source, target}));
    return *this;
}

GraphTracer GraphTracer::layoutCircle() {
    addTrace(key, "layoutCircle", json::array({}));
    return *this;
}

GraphTracer GraphTracer::layoutTree(json root, json sorted) {
    addTrace(key, "layoutTree", json::array({root, sorted}));
    return *this;
}

GraphTracer GraphTracer::layoutTree(json root) {
    addTrace(key, "layoutTree", json::array({root}));
    return *this;
}

GraphTracer GraphTracer::layoutTree() {
    addTrace(key, "layoutTree", json::array({}));
    return *this;
}

GraphTracer GraphTracer::layoutRandom() {
    addTrace(key, "layoutRandom", json::array({}));
    return *this;
}

GraphTracer GraphTracer::visit(json target, json source, json weight) {
    addTrace(key, "visit", json::array({target, source, weight}));
    return *this;
}

GraphTracer GraphTracer::visit(json target, json source) {
    addTrace(key, "visit", json::array({target, source}));
    return *this;
}

GraphTracer GraphTracer::visit(json target) {
    addTrace(key, "visit", json::array({target}));
    return *this;
}

GraphTracer GraphTracer::leave(json target, json source, json weight) {
    addTrace(key, "leave", json::array({target, source, weight}));
    return *this;
}

GraphTracer GraphTracer::leave(json target, json source) {
    addTrace(key, "leave", json::array({target, source}));
    return *this;
}

GraphTracer GraphTracer::leave(json target) {
    addTrace(key, "leave", json::array({target}));
    return *this;
}

GraphTracer GraphTracer::select(json target, json source) {
    addTrace(key, "select", json::array({target, source}));
    return *this;
}

GraphTracer GraphTracer::select(json target) {
    addTrace(key, "select", json::array({target}));
    return *this;
}

GraphTracer GraphTracer::deselect(json target, json source) {
    addTrace(key, "deselect", json::array({target, source}));
    return *this;
}

GraphTracer GraphTracer::deselect(json target) {
    addTrace(key, "deselect", json::array({target}));
    return *this;
}

GraphTracer GraphTracer::log(json logTracer) {
    addTrace(key, "log", json::array({logTracer}));
    return *this;
}
