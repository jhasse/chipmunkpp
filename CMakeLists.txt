cmake_minimum_required(VERSION 3.6)

project(chipmunkpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

set(BUILD_DEMOS OFF CACHE BOOL "Chipmunk Demos" FORCE)
add_subdirectory(chipmunk)

file(GLOB SOURCES src/*.cpp src/chipmunkpp/*.cpp)
add_library(chipmunkpp ${SOURCES})
target_include_directories(chipmunkpp PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/chipmunk/include/chipmunk
	${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(chipmunkpp PUBLIC chipmunk_static)
