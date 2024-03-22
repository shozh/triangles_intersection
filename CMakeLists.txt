cmake_minimum_required(VERSION 3.27)
project(triangles)

set(CMAKE_CXX_STANDARD 23)

include_directories(.)

add_executable(triangles
        addition.cpp
        addition.h
        line.cpp
        line.h
        main.cpp
        point.cpp
        point.h
        polygon.cpp
        polygon.h
        triangle.cpp
        triangle.h
        triangle_intersect.cpp
        triangle_intersect.h
        vector.cpp
        vector.h)
