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
    Submarine s{10, 10, 10};
    ASSERT_EQ(10, s.horizontal_position);
    ASSERT_EQ(10, s.depth);
    ASSERT_EQ(10, s.aim);
}

TEST_F(Day2Test, InitializesCommand)
{
    Command c{Movement::forward, 10};
    ASSERT_EQ(Movement::forward, c.movement);
    ASSERT_EQ(10, c.value);
}

TEST_F(Day2Test, SubmarineMovesForward)
{
    Submarine submarine{0,0, 0};
    submarine.actions = {
            { Movement::forward, Action::increase_horizontal_position},
    };
    submarine.perform_command({Movement::forward, 1});
    ASSERT_EQ(1, submarine.horizontal_position);
}

TEST_F(Day2Test, SubmarineIncreasesDepth)
{
    Submarine submarine{0,0, 0};
    submarine.actions = {
            { Movement::down, Action::increase_depth},
    };
    submarine.perform_command({Movement::down, 1});
    ASSERT_EQ(1, submarine.depth);
}

TEST_F(Day2Test, SubmarineDecreasesDepth)
{
    Submarine submarine{0,1, 0};
    submarine.actions = {
            { Movement::up, Action::decrease_depth}
    };
    submarine.perform_command({Movement::up, 1});
    ASSERT_EQ(0, submarine.depth);
}

TEST_F(Day2Test, SubmarineIncreasesAim)
{
    Submarine submarine{0,0, 0};
    submarine.actions = {
            { Movement::down, Action::increase_aim},
    };
    submarine.perform_command({Movement::down, 1});
    ASSERT_EQ(1, submarine.aim);
}

TEST_F(Day2Test, SubmarineDecreasesAim)
{
    Submarine submarine{0,0, 1};
    submarine.actions = {
            { Movement::up, Action::decrease_aim}
    };
    submarine.perform_command({Movement::up, 1});
    ASSERT_EQ(0, submarine.aim);
}

TEST_F(Day2Test, SubmarineIncreasesPositionAndDepth)
{
    Submarine submarine{5,5, 5};
    submarine.actions = {
            { Movement::forward, Action::increase_position_and_depth}
    };
    submarine.perform_command({Movement::forward, 5});
    ASSERT_EQ(10, submarine.horizontal_position);
    ASSERT_EQ(30, submarine.depth);
}

TEST_F(Day2Test, CorrectTotalCalculation)
{
    Submarine submarine{2,5, 0};

    ASSERT_EQ(10, submarine.calculateTotal());
}

TEST_F(Day2Test, Part1ExampleTest)
{
    Submarine submarine{0, 0, 0};
    submarine.actions = {
            { Movement::forward, Action::increase_horizontal_position},
            { Movement::down, Action::increase_depth},
            { Movement::up, Action::decrease_depth}
    };
    submarine.perform_command({Movement::forward, 5});
    submarine.perform_command({Movement::down, 5});
    submarine.perform_command({Movement::forward, 8});
    submarine.perform_command({Movement::up, 3});
    submarine.perform_command({Movement::down, 8});
    submarine.perform_command({Movement::forward, 2});
    ASSERT_EQ(15, submarine.horizontal_position);
    ASSERT_EQ(10, submarine.depth);
    ASSERT_EQ(150, submarine.calculateTotal());
}

TEST_F(Day2Test, Part2ExampleTest)
{
    Submarine submarine{0, 0, 0};
    submarine.actions = {
            { Movement::forward, Action::increase_position_and_depth},
            { Movement::down, Action::increase_aim},
            { Movement::up, Action::decrease_aim}
    };
    submarine.perform_command({Movement::forward, 5});
    submarine.perform_command({Movement::down, 5});
    submarine.perform_command({Movement::forward, 8});
    submarine.perform_command({Movement::up, 3});
    submarine.perform_command({Movement::down, 8});
    submarine.perform_command({Movement::forward, 2});
    ASSERT_EQ(15, submarine.horizontal_position);
    ASSERT_EQ(60, submarine.depth);
    ASSERT_EQ(900, submarine.calculateTotal());
}

int main(int ac, char *av[])
{
    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}
