cmake_minimum_required(VERSION 3.26)
project(Assignment3_Paradigms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_VISIBILITY_PRESET default)


# Create shared library for encryption and decryption
add_library(caesar SHARED encrypt.cpp decrypt.cpp)

# Create executable
add_executable(Assignment3_Paradigms main.cpp)

# Link the dynamic library to the executable
target_link_libraries(Assignment3_Paradigms caesar)

# Include directory for the header files
target_include_directories(Assignment3_Paradigms PRIVATE ${CMAKE_SOURCE_DIR})