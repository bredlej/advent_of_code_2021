//
// Created by geoco on 02.12.2021.
//

#ifndef ADVENT_OF_CODE_2021_DAY2_H
#define ADVENT_OF_CODE_2021_DAY2_H

#include <cstdint>
#include <unordered_map>
#include <functional>

struct Submarine ;

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
    uint32_t aim;
    std::unordered_map<Movement, std::function<void(Submarine&, const uint32_t)>> actions;
    void perform_command(const Command &&command);
    void action(const Command &command);
    uint32_t calculateTotal() const;
};

namespace Action {
    constexpr auto increase_horizontal_position = [](Submarine &sub, const uint32_t value) { sub.horizontal_position += value; };
    constexpr auto increase_depth = [](Submarine &sub, const uint32_t value) { sub.depth += value; };
    constexpr auto decrease_depth = [](Submarine &sub, const uint32_t value) { sub.depth -= value; };
    constexpr auto increase_aim = [](Submarine &sub, const uint32_t value) { sub.aim += value; };
    constexpr auto decrease_aim = [](Submarine &sub, const uint32_t value) { sub.aim -= value; };
    constexpr auto increase_position_and_depth = [](Submarine &sub, const uint32_t value) {
        sub.horizontal_position += value;
        sub.depth += (sub.aim * value);
    };

}


#endif//ADVENT_OF_CODE_2021_DAY2_H
