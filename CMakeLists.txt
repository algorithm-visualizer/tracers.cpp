cmake_minimum_required(VERSION 3.2)

project(algorithm-visualizer VERSION 2.3.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
install(DIRECTORY include/
        DESTINATION include/${PROJECT_NAME}
        FILES_MATCHING PATTERN "*.h*")

add_subdirectory(test)
