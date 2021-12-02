//
// Created by geoco on 02.12.2021.
//
#include <gtest/gtest.h>
#include <day2.h>

class Day2Test : public testing::Test {
protected:
    Day2Test() = default;
};

TEST_F(Day2Test, InitializesSubmarine)
{
    Submarine s{10, 10};
    ASSERT_EQ(10, s.horizontal_position);
    ASSERT_EQ(10, s.depth);
}

TEST_F(Day2Test, InitializesCommand)
{
    Command c{Movement::forward, 10};
    ASSERT_EQ(Movement::forward, c.movement);
    ASSERT_EQ(10, c.value);
}

TEST_F(Day2Test, SubmarineMovesForward)
{
    Submarine submarine{0,0};
    submarine.action({Movement::forward, 1});
    ASSERT_EQ(1, submarine.horizontal_position);
}

TEST_F(Day2Test, SubmarineIncreasesDepth)
{
    Submarine submarine{0,0};
    submarine.action({Movement::down, 1});
    ASSERT_EQ(1, submarine.depth);
}

TEST_F(Day2Test, SubmarineDecreasesDepth)
{
    Submarine submarine{0,1};
    submarine.action({Movement::up, 1});
    ASSERT_EQ(0, submarine.depth);
}

TEST_F(Day2Test, CorrectTotalCalculation)
{
    Submarine submarine{2,5};
    ASSERT_EQ(10, submarine.calculateTotal());
}

TEST_F(Day2Test, Part1ExampleTest)
{
    Submarine submarine{0, 0};
    submarine.action({Movement::forward, 5});
    submarine.action({Movement::down, 5});
    submarine.action({Movement::forward, 8});
    submarine.action({Movement::up, 3});
    submarine.action({Movement::down, 8});
    submarine.action({Movement::forward, 2});
    ASSERT_EQ(15, submarine.horizontal_position);
    ASSERT_EQ(10, submarine.depth);
    ASSERT_EQ(150, submarine.calculateTotal());
}

int main(int ac, char *av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
