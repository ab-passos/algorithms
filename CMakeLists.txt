cmake_minimum_required (VERSION 2.6)
project (Tutorial)
find_package(Boost 1.45.0 COMPONENTS filesystem regex)
include_directories(${Boost_INCLUDE_DIRS})
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "-stdlib=libc++ -std=gnu++11")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories("/usr/local/include")
link_directories("/usr/local/lib")


add_executable(problem1 problem1.cpp)
add_executable(problem2 problem2.cpp)
add_executable(problem3 problem3.cpp)
add_executable(problem4 problem4.cpp)
add_executable(problem5 problem5.cpp)
add_executable(problem6 problem6.cpp)
target_link_libraries(problem6 ${GTEST_LIBRARIES} pthread)
