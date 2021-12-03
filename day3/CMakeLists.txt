add_library(day3 day3.cpp)

add_executable(day3-exec main.cpp)
target_link_libraries(day3-exec day3)

add_executable(day3-test test_day3.cpp)
target_link_libraries(day3-test gtest day3)
add_test(TestDay3 day3-test)
target_include_directories(day3 PUBLIC .)