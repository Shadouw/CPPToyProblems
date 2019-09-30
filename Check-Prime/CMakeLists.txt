# Get the problem name from the current directory
get_filename_component(problem ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required (VERSION 3.5)

# Name the project after the problem
project(${problem} CXX)

# Add all cpp and h files
file(GLOB SRC_FILES
    "*.h"
    "*.cpp"
)

add_executable(${problem} ${SRC_FILES})
