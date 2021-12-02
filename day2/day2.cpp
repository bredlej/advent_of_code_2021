//
// Created by geoco on 02.12.2021.
//
#include "day2.h"

#include <unordered_map>
#include <functional>

static std::unordered_map<Movement, std::function<void(Submarine&, const uint32_t)>> actions = {
        { Movement::forward, [](Submarine &sub, const uint32_t value){ sub.horizontal_position += value; }},
        { Movement::down, [](Submarine &sub, const uint32_t value){ sub.depth += value; }},
        { Movement::up, [](Submarine &sub, const uint32_t value){ sub.depth -= value; }}
};

void Submarine::action(const Command &&command) {
        action(command);
}

uint32_t Submarine::calculateTotal() const {
    return depth * horizontal_position;
}
void Submarine::action(const Command &command) {
    actions[command.movement](*this, command.value);
}
