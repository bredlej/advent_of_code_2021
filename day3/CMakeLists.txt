add_executable(day3-exec main.cpp)
target_link_libraries(day3-exec day3)

add_executable(day3-test test_day3.cpp)
target_link_libraries(day3-test gtest)
add_test(TestDay3 day3-test)

target_include_directories(day3-exec PUBLIC .)
target_include_directories(day3-test PUBLIC .)

add_custom_command(
        TARGET day3-exec POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/day3/inputfile
        ${CMAKE_CURRENT_BINARY_DIR})