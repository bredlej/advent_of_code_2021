//
// Created by geoco on 03.12.2021.
//
#include <day3.h>
#include <gtest/gtest.h>

class Day3Test : public testing::Test {
public:
    std::vector<std::string> input = {
            "00100",
            "11110",
            "10110",
            "10111",
            "10101",
            "01111",
            "00111",
            "11100",
            "10000",
            "11001",
            "00010",
            "01010"};

protected:
    Day3Test() = default;
};

TEST_F(Day3Test, DeterminesCorrectSize) {
    ASSERT_EQ(5, determine_bitsize_with_assertions(input));
}

TEST_F(Day3Test, ConvertsToDecimal) {
    ASSERT_EQ(5, binary_to_decimal("01010"));
}

int main(int ac, char *av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}