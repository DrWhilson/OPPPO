#Lab
set(COMPILE_FLAGS "--debug")
set(SOURCE_EXE lab1.cpp)
set(SOURCE_LIB figure.cpp lib.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")

add_library(libs STATIC ${SOURCE_LIB})

add_executable(lab1 ${SOURCE_EXE})

target_link_libraries(lab1 libs)
