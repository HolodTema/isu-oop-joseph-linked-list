cmake_minimum_required(VERSION 4.1)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp
        josephus.hpp
        josephus.cpp
        josephusOptimized.hpp
        josephusOptimized.cpp
        LinkedList.hpp)
