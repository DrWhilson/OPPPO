#Lab
cmake_minimum_required(VERSION 3.5)

project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(COMPILE_FLAGS "--debug")
set(SOURCE_EXE lab1.cpp)
set(SOURCE_LIB figure.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

include_directories(./)

add_library(figure STATIC ${SOURCE_LIB})

add_executable(lab1 ${SOURCE_EXE})

target_link_libraries(lab1 figure)

#CppUTest
# find_package(CppUTest REQUIRED)
include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        master
)

set(TESTS OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

add_executable(example_test main_test.cpp)

target_link_libraries(example_test PRIVATE CppUTest CppUTestExt)
add_test(example_test example_test)
