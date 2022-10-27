cmake_minimum_required(VERSION 3.23)
project(lab1)
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
FetchContent_MakeAvailable(googletest)
add_executable(lab1 test.cpp BigInt.cpp BigInt.h)
target_link_libraries(lab1 gtest_main)
