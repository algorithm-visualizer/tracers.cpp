find_package(CURL REQUIRED)

add_executable(test main.cpp)

target_link_libraries(test ${CURL_LIBRARIES})
