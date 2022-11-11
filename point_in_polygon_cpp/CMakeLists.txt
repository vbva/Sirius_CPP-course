cmake_minimum_required(VERSION 3.23)
project(point_in_polygon_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(point_in_polygon_cpp main.cpp point_in_poly.h point_in_poly.cpp)
