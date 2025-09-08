cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(tests)

include_directories(include)
add_executable(rpn_calculator
    src/main.cpp
    include/rpn.h
    src/rpn.cpp
)