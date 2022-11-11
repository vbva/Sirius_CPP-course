cmake_minimum_required(VERSION 3.23)
project(prime)

set(CMAKE_CXX_STANDARD 14)

add_executable(prime main.cpp prime_head.h prime.cpp)
