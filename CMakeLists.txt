cmake_minimum_required(VERSION 4.0)
project(sourceCode)

set(CMAKE_CXX_STANDARD 20)

add_executable(sourceCode main.cpp
        Node.cpp
        Tree.cpp
        )
