#ifndef VERTICALLAYOUT_H
#define VERTICALLAYOUT_H

#include "Layout.h"

class VerticalLayout : public Layout {
public:
    VerticalLayout(const commander_list &children, const string &className = "VerticalLayout") : Layout(children,
                                                                                                       className) {
    }
};

#endif
