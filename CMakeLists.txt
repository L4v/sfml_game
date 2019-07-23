cmake_minimum_required(VERSION 3.2)
project(engine)
include_directories("./_include")


set(EXECUTABLE_NAME "engine")


file(GLOB HEADERS "./_include/*.hpp")
file(GLOB SOURCES "./_src/*.cpp")
add_executable(${EXECUTABLE_NAME} ${HEADERS} ${SOURCES})


target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics)
