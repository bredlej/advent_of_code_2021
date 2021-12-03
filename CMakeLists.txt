cmake_minimum_required(VERSION 3.18.4)
project(advent_of_code_2021)

set(CMAKE_CXX_STANDARD 20)

add_executable(advent_of_code_2021 main.cpp)
add_subdirectory(extern)
add_subdirectory(day1)
add_subdirectory(day2)
add_subdirectory(day3)
include(FetchContent)
include(CTest)
enable_testing()
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
