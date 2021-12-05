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

TEST_F(Day3Test, CalculatesMostCommonBitsFromString) {
    processor<uint32_t, 4, most_common_bit> p;
    p.msb_array = p.feed_data("0000");
    ASSERT_EQ(0, p.msb_array[0].yield());
    ASSERT_EQ(0, p.msb_array[1].yield());
    ASSERT_EQ(0, p.msb_array[2].yield());
    ASSERT_EQ(0, p.msb_array[3].yield());

    p.msb_array = p.feed_data("1111");
    ASSERT_EQ(-1, p.msb_array[0].yield());
    ASSERT_EQ(-1, p.msb_array[1].yield());
    ASSERT_EQ(-1, p.msb_array[2].yield());
    ASSERT_EQ(-1, p.msb_array[3].yield());

    p.msb_array = p.feed_data("1111");
    ASSERT_EQ(1, p.msb_array[0].yield());
    ASSERT_EQ(1, p.msb_array[1].yield());
    ASSERT_EQ(1, p.msb_array[2].yield());
    ASSERT_EQ(1, p.msb_array[3].yield());
}

TEST_F(Day3Test, RunProcessesAllData) {
    const std::vector<std::string> data{"0000", "1111", "1111"};
    processor<uint32_t, 4, most_common_bit> p;
    p.run(data);
    ASSERT_EQ(1, p.msb_array[0].yield());
    ASSERT_EQ(1, p.msb_array[1].yield());
    ASSERT_EQ(1, p.msb_array[2].yield());
    ASSERT_EQ(1, p.msb_array[3].yield());
}

TEST_F(Day3Test, CalculatesGamma) {
    processor<uint32_t, 5, most_common_bit> p;
    p.run(input);
    ASSERT_EQ(22, p.gamma());
}

TEST_F(Day3Test, CalculatesEpsilon) {
    processor<uint32_t, 5, most_common_bit> p;
    p.run(input);
    ASSERT_EQ(9, p.epsilon());
}

TEST_F(Day3Test, CalculatesPowerConsumption) {
    processor<uint32_t, 5, most_common_bit> p;
    p.run(input);
    ASSERT_EQ(198, p.power_consumption());
}

int main(int ac, char *av[]) {
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}