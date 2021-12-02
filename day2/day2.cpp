//
// Created by geoco on 02.12.2021.
//
#include "day2.h"

void Submarine::perform_command(const Command &&command) {
    perform_command(command);
}

uint32_t Submarine::calculateTotal() const {
    return depth * horizontal_position;
}

void Submarine::perform_command(const Command &command) {
    actions[command.movement](*this, command.value);
}
