find_package(CURL REQUIRED)

add_executable(tracers main.cpp)

target_link_libraries(tracers PRIVATE ${CURL_LIBRARIES})

add_test(test tracers)