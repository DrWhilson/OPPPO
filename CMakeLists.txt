#Lab
cmake_minimum_required(VERSION 3.5)

project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

include_directories(lab1)
link_directories(lab1)
include_directories(runTests)
link_directories(runTests)

add_subdirectory(src)
add_subdirectory(tests)
