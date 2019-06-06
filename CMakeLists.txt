cmake_minimum_required(VERSION 3.13)
project(senku)

set(CMAKE_CXX_STANDARD 14)

add_executable(senku main.cpp senku.h senku.cpp)
