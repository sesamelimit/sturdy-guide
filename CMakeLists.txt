cmake_minimum_required(VERSION 3.22)
project(fiit)

set(CMAKE_CXX_STANDARD 14)

add_executable(fiit misc_cpp.cpp base64.cpp dyn_arrays.cpp files.cpp functions.cpp loops.cpp sailstar.cpp triangles.cpp)
