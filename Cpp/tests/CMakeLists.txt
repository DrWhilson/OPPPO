#GoogleTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runTests main_test.cpp)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread libs)
