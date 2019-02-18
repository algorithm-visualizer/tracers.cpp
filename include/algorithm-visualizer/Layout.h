#ifndef LAYOUT_H
#define LAYOUT_H

#include "Commander.h"

class Layout : public Commander {
protected:
    using commander_list = std::vector<Commander>;

private:
    static std::vector<string> keys(const commander_list &children) {
        std::vector<string> keys;
        keys.reserve(children.size());
        for (Commander commander : children) {
            keys.push_back(commander.key);
        }
        return keys;
    }

public:
    static void setRoot(const Commander &child) {
        command(nullptr, "setRoot", {child.key});
    }

    Layout(const commander_list &children, const string &className = "Layout") : Commander({keys(children)},
                                                                                           className) {
    }

    void add(const Commander &child, int index) {
        command("add", {child.key, index});
    }

    void add(const Commander &child) {
        command("add", {child.key});
    }

    void remove(const Commander &child) {
        command("remove", {child.key});
    }

    void removeAll() {
        command("remove", {});
    }
};

#endif
