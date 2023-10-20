cmake_minimum_required(VERSION 3.26)
project(Assignment3_Paradigms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Assignment3_Paradigms main.cpp
        test_caesar
        caesar.h
)

add_library(Assignment3_Paradigms SHARED encrypt.cpp decrypt.cpp)
target_link_libraries(test_caesar dl)
