cmake_minimum_required(VERSION 3.22)
project(fiit)

set(CMAKE_CXX_STANDARD 14)

add_executable(fiit functions.cpp dyn_arrays.cpp files.cpp triangles.cpp loops.cpp)
