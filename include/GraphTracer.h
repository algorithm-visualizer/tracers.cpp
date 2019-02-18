#ifndef GRAPHTRACER_H
#define GRAPHTRACER_H

#include "Tracer.h"
#include "LogTracer.h"

class GraphTracer : public Tracer {
public:
    GraphTracer(const string &title = "", const string &className = "GraphTracer") : Tracer(title, className) {
    }

    void set(const json &array2d) {
        command("set", {array2d});
    }

    GraphTracer directed(bool isDirected) {
        command("directed", {isDirected});
        return *this;
    }

    GraphTracer directed() {
        command("directed", {});
        return *this;
    }

    GraphTracer weighted(bool isWeighted) {
        command("weighted", {isWeighted});
        return *this;
    }

    GraphTracer weighted() {
        command("weighted", {});
        return *this;
    }

    GraphTracer layoutCircle() {
        command("layoutCircle", {});
        return *this;
    }

    GraphTracer layoutTree(const json &root, bool sorted) {
        command("layoutTree", {root, sorted});
        return *this;
    }

    GraphTracer layoutTree(const json &root) {
        command("layoutTree", {root});
        return *this;
    }

    GraphTracer layoutTree() {
        command("layoutTree", {});
        return *this;
    }

    GraphTracer layoutRandom() {
        command("layoutRandom", {});
        return *this;
    }

    void addNode(const json &id, double weight, double x, double y, int visitedCount, int selectedCount) {
        command("addNode", {id, weight, x, y, visitedCount, selectedCount});
    }

    void addNode(const json &id, double weight, double x, double y, int visitedCount) {
        command("addNode", {id, weight, x, y, visitedCount});
    }

    void addNode(const json &id, double weight, double x, double y) {
        command("addNode", {id, weight, x, y});
    }

    void addNode(const json &id, double weight, double x) {
        command("addNode", {id, weight, x});
    }

    void addNode(const json &id, double weight) {
        command("addNode", {id, weight});
    }

    void addNode(const json &id) {
        command("addNode", {id});
    }

    void updateNode(const json &id, double weight, double x, double y, int visitedCount, int selectedCount) {
        command("updateNode", {id, weight, x, y, visitedCount, selectedCount});
    }

    void updateNode(const json &id, double weight, double x, double y, int visitedCount) {
        command("updateNode", {id, weight, x, y, visitedCount});
    }

    void updateNode(const json &id, double weight, double x, double y) {
        command("updateNode", {id, weight, x, y});
    }

    void updateNode(const json &id, double weight, double x) {
        command("updateNode", {id, weight, x});
    }

    void updateNode(const json &id, double weight) {
        command("updateNode", {id, weight});
    }

    void updateNode(const json &id) {
        command("updateNode", {id});
    }

    void removeNode(const json &id) {
        command("removeNode", {id});
    }

    void addEdge(const json &source, const json &target, double weight, int visitedCount, int selectedCount) {
        command("addEdge", {source, target, weight, visitedCount, selectedCount});
    }

    void addEdge(const json &source, const json &target, double weight, int visitedCount) {
        command("addEdge", {source, target, weight, visitedCount});
    }

    void addEdge(const json &source, const json &target, double weight) {
        command("addEdge", {source, target, weight});
    }

    void addEdge(const json &source, const json &target) {
        command("addEdge", {source, target});
    }

    void updateEdge(const json &source, const json &target, double weight, int visitedCount, int selectedCount) {
        command("updateEdge", {source, target, weight, visitedCount, selectedCount});
    }

    void updateEdge(const json &source, const json &target, double weight, int visitedCount) {
        command("updateEdge", {source, target, weight, visitedCount});
    }

    void updateEdge(const json &source, const json &target, double weight) {
        command("updateEdge", {source, target, weight});
    }

    void updateEdge(const json &source, const json &target) {
        command("updateEdge", {source, target});
    }

    void removeEdge(const json &source, const json &target) {
        command("removeEdge", {source, target});
    }

    void visit(const json &target, const json &source, double weight) {
        command("visit", {target, source, weight});
    }

    void visit(const json &target, const json &source) {
        command("visit", {target, source});
    }

    void visit(const json &target) {
        command("visit", {target});
    }

    void leave(const json &target, const json &source, double weight) {
        command("leave", {target, source, weight});
    }

    void leave(const json &target, const json &source) {
        command("leave", {target, source});
    }

    void leave(const json &target) {
        command("leave", {target});
    }

    void select(const json &target, const json &source) {
        command("select", {target, source});
    }

    void select(const json &target) {
        command("select", {target});
    }

    void deselect(const json &target, const json &source) {
        command("deselect", {target, source});
    }

    void deselect(const json &target) {
        command("deselect", {target});
    }

    void log(LogTracer &logTracer) {
        command("log", {logTracer.key});
    }
};

#endif
