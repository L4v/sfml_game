cmake_minimum_required(VERSION 3.2)
project(sfml_game)
include_directories("./_include")


set(SFML_DIR "./_lib/cmake/SFML")
set(EXECUTABLE_NAME "engine")


file(GLOB HEADERS "./_include/*.hpp")
file(GLOB SOURCES "./_src/*.cpp")
add_executable(${EXECUTABLE_NAME} ${HEADERS} ${SOURCES})

find_package(SFML 2 REQUIRED graphics system window network audio)

if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()


