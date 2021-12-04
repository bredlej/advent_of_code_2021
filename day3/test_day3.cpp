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
    ASSERT_EQ(10, binary_to_decimal("01010"));
}

TEST_F(Day3Test, MostCommonBitGeneratorWorks) {
    most_common_bit a, b, c, nonused;

    auto a_ = a(0, a(1, a(0)));

    auto b_ = b(1, b(0, b(1)));

    auto c_ = c(0, c(0));

    auto d_ = c(1);
    d_(0);

    ASSERT_EQ(0, a_.yield());
    ASSERT_EQ(1, b_.yield());
    ASSERT_EQ(0, c_.yield());
    ASSERT_EQ(1, d_.yield());
    ASSERT_EQ(1, nonused(1));
    ASSERT_EQ(1, nonused(1));
    ASSERT_EQ(0, nonused(0));
    ASSERT_TRUE(&a_ != &b_ and &b_ != &c_ and &c_ != &d_ and &d_ != &nonused);
}

TEST_F(Day3Test, ParsesInput)
{
    int size = determine_bitsize_with_assertions(input);
    //auto test = parse_input<>(input);
}

int main(int ac, char *av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}