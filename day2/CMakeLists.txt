add_library(day2 day2.cpp)

add_executable(day2-exec main.cpp)
target_link_libraries(day2-exec day2)

add_executable(day2-test test_day2.cpp)
target_link_libraries(day2-test gtest day2)
add_test(TestDay2 day2-test)
target_include_directories(day2 PUBLIC .)