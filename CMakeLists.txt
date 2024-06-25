cmake_minimum_required(VERSION 3.27)
project(FalloutCharacterPlanner)

set(CMAKE_CXX_STANDARD 17)

add_executable(FalloutCharacterPlanner main.cpp
        ahUnitTest.h
        ahFunctions.cpp
        ahUnitTest.cpp)
