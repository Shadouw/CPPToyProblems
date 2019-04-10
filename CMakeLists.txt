# Get the problem name from the current directory
get_filename_component(problem ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Basic CMake project
cmake_minimum_required (VERSION 3.5)

# Name the project after the problem
project(${problem} CXX)

# Enable C++11 features on gcc/clang
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "(GNU|Clang)")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

add_subdirectory(Check-Prime)
add_subdirectory(Euclidean-Algorithm)
add_subdirectory(Fibonacci)
add_subdirectory(Knights-Tour)
add_subdirectory(Prime-Factorization)
add_subdirectory(Queens-Problem)
add_subdirectory(Sieve-of-Eratosthenes)
add_subdirectory(Tower-of-Hanoi)

