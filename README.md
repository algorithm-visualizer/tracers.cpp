# tracers.cpp [![API reference](https://img.shields.io/badge/documentation-cpp-red.svg?style=flat-square)](https://algorithm-visualizer.github.io/tracers.cpp/) [![Travis (.com)](https://img.shields.io/travis/com/algorithm-visualizer/tracers.cpp.svg?style=flat-square)](https://travis-ci.com/algorithm-visualizer/tracers.cpp)

> This repository is part of the project [Algorithm Visualizer](https://github.com/algorithm-visualizer).

`tracers.cpp` is a visualization library for C++.
You can use it on [algorithm-visualizer.org](https://algorithm-visualizer.org/) or locally on your machine.

## Prerequisites

- [libcurl](https://curl.haxx.se/libcurl/)

## Installation

1. Download and extract the source code in the [latest release](https://github.com/algorithm-visualizer/tracers.cpp/releases/latest).

2. Change directory to it and run:

```bash
mkdir build

cd build

cmake ..

make install
```

## Usage

```cpp
// import visualization libraries {
#include "algorithm-visualizer.h"
// }

#include <vector>
#include <string>

// define tracer variables {
Array2DTracer array2dTracer = Array2DTracer("Grid");
LogTracer logTracer = LogTracer("Console");
// }

// define input variables
std::vector<std::string> messages{
        "Visualize",
        "your",
        "own",
        "code",
        "here!",
};

// highlight each line of messages recursively
void highlight(int line) {
    if (line >= messages.size()) return;
    std::string message = messages[line];
    // visualize {
    logTracer.println(message);
    array2dTracer.selectRow(line, 0, message.size() - 1);
    Tracer::delay();
    array2dTracer.deselectRow(line, 0, message.size() - 1);
    // }
    highlight(line + 1);
}

int main() {
    // visualize {
    Layout::setRoot(VerticalLayout({array2dTracer, logTracer}));
    array2dTracer.set(messages);
    Tracer::delay();
    // }
    highlight(0);
    return 0;
}
```

Check out the [API reference](https://algorithm-visualizer.github.io/tracers.cpp/) for more information.

## Contributing

Check out the [contributing guidelines](https://github.com/algorithm-visualizer/tracers.cpp/blob/master/CONTRIBUTING.md).
