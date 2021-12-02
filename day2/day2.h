//
// Created by geoco on 02.12.2021.
//

#ifndef ADVENT_OF_CODE_2021_DAY2_H
#define ADVENT_OF_CODE_2021_DAY2_H

#include <cstdint>

enum class Movement {
    forward, down, up
};

struct Command {
    Movement movement;
    uint32_t value;
};

struct Submarine {
    uint32_t horizontal_position;
    uint32_t depth;

    void action(const Command &&command);
    void action(const Command &command);
    uint32_t calculateTotal() const;
};

#endif//ADVENT_OF_CODE_2021_DAY2_H
