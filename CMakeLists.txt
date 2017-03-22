cmake_minimum_required (VERSION 2.6)
project (Tutorial)
find_package(Boost 1.45.0 COMPONENTS filesystem regex)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(problem1 problem1.cpp)
add_executable(problem2 problem2.cpp)
add_executable(problem3 problem3.cpp)
add_executable(problem4 problem4.cpp)
