#Lab
cmake_minimum_required(VERSION 3.22)

project(lab)

set(COMPILE_FLAGS "--debug")

set(SOURCE_EXE lab1.cpp)

set(SOURCE_LIB figure.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

add_library(figure STATIC ${SOURCE_LIB})

add_executable(lab1 ${SOURCE_EXE})

target_link_libraries(lab1 figure)

#CppUTest
include(FetchContent)
FetchContent_Declare(
  CppUTest
  GIT_REPOSITORY https://github.com/cpputest/cpputest.git
  GIT_TAG        master
)

set(TEST OFF CACHE BOOL "Switch off CppUTest Test build")
FetchContent_MakeAvailable(CppUTest)

add_executable(test test.cpp)

target_link_libraries(test PRIVATE
  CppUTest::CppUTest
  CppUTest::CppUTestExt)
