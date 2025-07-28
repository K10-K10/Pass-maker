cmake_minimum_required(VERSION 3.10)
project(Pass-maker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB_RECURSE SOURCES
    src/*.cpp
    include/**/*.cpp
    include/**/*.hpp
)
add_executable(Pass-maker ${SOURCES})
