cmake_minimum_required(VERSION 3.9)

project(algorithm-visualizer VERSION 2.3.6)

set(CMAKE_CXX_STANDARD 11)

execute_process(
        COMMAND curl --create-dirs -o ${CMAKE_SOURCE_DIR}/include/nlohmann/json.hpp -L "https://github.com/nlohmann/json/releases/download/v3.6.1/json.hpp"
)
include_directories(include)
install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*")

enable_testing()
add_subdirectory(test)
