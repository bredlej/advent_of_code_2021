
// Created by geoco on 02.12.2021.
//
#include <day2.h>
#include <vector>
#include <chrono>
#include <cstdio>

void run_submarine(const std::vector<Command> &commands, const auto &forward_action, const auto &down_action, const auto &up_action) {
    auto before = std::chrono::high_resolution_clock::now();
    Submarine submarine{0, 0, 0};
    submarine.actions = {
            { Movement::forward, forward_action},
            { Movement::down, down_action},
            { Movement::up, up_action}
    };
    for (auto &command : commands) {
        submarine.perform_command(command);
    }
    auto after = std::chrono::high_resolution_clock::now() - before;
    std::printf("Elapsed time: %lld microseconds\n", std::chrono::duration_cast<std::chrono::microseconds>(after).count());
    std::printf("Submarine at horizontal position=[%d], depth=[%d] (Total: %d)\n", submarine.horizontal_position, submarine.depth, submarine.calculateTotal());
}

int main() {
    const std::vector<Command> commands = {
            {Movement::forward, 4},
            {Movement::down, 8},
            {Movement::down, 3},
            {Movement::down, 1},
            {Movement::forward, 8},
            {Movement::up, 6},
            {Movement::down, 4},
            {Movement::forward, 2},
            {Movement::down, 4},
            {Movement::down, 6},
            {Movement::down, 7},
            {Movement::forward, 1},
            {Movement::down, 4},
            {Movement::down, 6},
            {Movement::forward, 7},
            {Movement::down, 2},
            {Movement::up, 8},
            {Movement::up, 3},
            {Movement::forward, 1},
            {Movement::forward, 2},
            {Movement::down, 3},
            {Movement::down, 8},
            {Movement::forward, 6},
            {Movement::forward, 5},
            {Movement::down, 4},
            {Movement::down, 1},
            {Movement::up, 5},
            {Movement::down, 5},
            {Movement::down, 2},
            {Movement::up, 6},
            {Movement::forward, 4},
            {Movement::forward, 3},
            {Movement::down, 8},
            {Movement::down, 9},
            {Movement::up, 2},
            {Movement::forward, 1},
            {Movement::forward, 2},
            {Movement::down, 1},
            {Movement::forward, 3},
            {Movement::down, 7},
            {Movement::up, 6},
            {Movement::down, 1},
            {Movement::down, 7},
            {Movement::down, 5},
            {Movement::forward, 8},
            {Movement::down, 5},
            {Movement::down, 1},
            {Movement::down, 7},
            {Movement::up, 9},
            {Movement::forward, 6},
            {Movement::up, 8},
            {Movement::down, 3},
            {Movement::down, 9},
            {Movement::down, 3},
            {Movement::forward, 2},
            {Movement::forward, 1},
            {Movement::forward, 4},
            {Movement::down, 7},
            {Movement::up, 8},
            {Movement::down, 1},
            {Movement::up, 1},
            {Movement::forward, 4},
            {Movement::down, 7},
            {Movement::forward, 5},
            {Movement::forward, 2},
            {Movement::forward, 1},
            {Movement::up, 8},
            {Movement::down, 2},
            {Movement::up, 6},
            {Movement::down, 7},
            {Movement::down, 4},
            {Movement::up, 6},
            {Movement::forward, 2},
            {Movement::forward, 8},
            {Movement::down, 8},
            {Movement::down, 2},
            {Movement::forward, 2},
            {Movement::forward, 9},
            {Movement::down, 1},
            {Movement::forward, 5},
            {Movement::down, 4},
            {Movement::forward, 4},
            {Movement::down, 2},
            {Movement::down, 1},
            {Movement::forward, 7},
            {Movement::down, 1},
            {Movement::down, 5},
            {Movement::down, 5},
            {Movement::up, 5},
            {Movement::forward, 7},
            {Movement::forward, 6},
            {Movement::forward, 3},
            {Movement::forward, 9},
            {Movement::forward, 3},
            {Movement::forward, 5},
            {Movement::down, 8},
            {Movement::down, 9},
            {Movement::forward, 7},
            {Movement::up, 5},
            {Movement::up, 7},
            {Movement::down, 5},
            {Movement::up, 9},
            {Movement::forward, 9},
            {Movement::up, 8},
            {Movement::up, 2},
            {Movement::forward, 5},
            {Movement::down, 2},
            {Movement::forward, 2},
            {Movement::down, 4},
            {Movement::up, 4},
            {Movement::down, 2},
            {Movement::up, 3},
            {Movement::up, 8},
            {Movement::down, 3},
            {Movement::down, 4},
            {Movement::down, 7},
            {Movement::forward, 3},
            {Movement::forward, 9},
            {Movement::down, 1},
            {Movement::down, 2},
            {Movement::down, 5},
            {Movement::down, 1},
            {Movement::forward, 2},
            {Movement::forward, 2},
            {Movement::up, 8},
            {Movement::down, 4},
            {Movement::forward, 7},
            {Movement::up, 6},
            {Movement::down, 9},
            {Movement::down, 6},
            {Movement::up, 1},
            {Movement::down, 2},
            {Movement::forward, 6},
            {Movement::down, 4},
            {Movement::up, 1},
            {Movement::forward, 3},
            {Movement::down, 4},
            {Movement::down, 1},
            {Movement::up, 8},
            {Movement::forward, 3},
            {Movement::down, 5},
            {Movement::up, 2},
            {Movement::down, 8},
            {Movement::down, 4},
            {Movement::up, 2},
            {Movement::down, 2},
            {Movement::forward, 6},
            {Movement::up, 4},
            {Movement::up, 2},
            {Movement::down, 2},
            {Movement::forward, 7},
            {Movement::down, 5},
            {Movement::forward, 2},
            {Movement::forward, 8},
            {Movement::up, 3},
            {Movement::forward, 5},
            {Movement::up, 6},
            {Movement::down, 4},
            {Movement::down, 1},
            {Movement::down, 8},
            {Movement::down, 2},
            {Movement::forward, 8},
            {Movement::up, 2},
            {Movement::down, 5},
            {Movement::up, 8},
            {Movement::down, 1},
            {Movement::down, 1},
            {Movement::down, 5},
            {Movement::up, 4},
            {Movement::down, 1},
            {Movement::down, 3},
            {Movement::down, 8},
            {Movement::forward, 6},
            {Movement::down, 9},
            {Movement::forward, 6},
            {Movement::up, 2},
            {Movement::forward, 1},
            {Movement::forward, 9},
            {Movement::down, 9},
            {Movement::down, 3},
            {Movement::down, 9},
            {Movement::down, 6},
            {Movement::down, 4},
            {Movement::down, 8},
            {Movement::forward, 1},
            {Movement::down, 1},
            {Movement::forward, 2},
            {Movement::up, 2},
            {Movement::forward, 8},
            {Movement::down, 1},
            {Movement::up, 6},
            {Movement::down, 4},
            {Movement::down, 3},
            {Movement::forward, 8},
            {Movement::up, 7},
            {Movement::down, 6},
            {Movement::down, 1},
            {Movement::down, 2},
            {Movement::forward, 1},
            {Movement::up, 5},
            {Movement::up, 7},
            {Movement::down, 6},
            {Movement::down, 4},
            {Movement::down, 5},
            {Movement::forward, 9},
            {Movement::down, 7},
            {Movement::down, 9},
            {Movement::down, 5},
            {Movement::forward, 9},
            {Movement::forward, 7},
            {Movement::forward, 9},
            {Movement::forward, 8},
            {Movement::up, 4},
            {Movement::forward, 5},
            {Movement::down, 7},
            {Movement::forward, 8},
            {Movement::up, 1},
            {Movement::forward, 3},
            {Movement::forward, 2},
            {Movement::forward, 2},
            {Movement::down, 7},
            {Movement::forward, 9},
            {Movement::down, 7},
            {Movement::down, 9},
            {Movement::forward, 6},
            {Movement::forward, 8},
            {Movement::up, 5},
            {Movement::up, 8},
            {Movement::up, 7},
            {Movement::up, 6},
            {Movement::forward, 7},
            {Movement::down, 6},
            {Movement::down, 5},
            {Movement::down, 3},
            {Movement::forward, 7},
            {Movement::down, 7},
            {Movement::forward, 6},
            {Movement::down, 4},
            {Movement::down, 2},
            {Movement::down, 9},
            {Movement::down, 2},
            {Movement::up, 8},
            {Movement::down, 8},
            {Movement::down, 3},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::up, 6},
            {Movement::down, 9},
            {Movement::forward, 1},
            {Movement::down, 3},
            {Movement::forward, 9},
            {Movement::down, 6},
            {Movement::forward, 9},
            {Movement::forward, 8},
            {Movement::forward, 5},
            {Movement::up, 2},
            {Movement::forward, 5},
            {Movement::up, 7},
            {Movement::down, 6},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::forward, 2},
            {Movement::down, 7},
            {Movement::down, 8},
            {Movement::up, 1},
            {Movement::forward, 3},
            {Movement::forward, 5},
            {Movement::down, 3},
            {Movement::forward, 8},
            {Movement::up, 7},
            {Movement::forward, 9},
            {Movement::forward, 6},
            {Movement::forward, 1},
            {Movement::forward, 7},
            {Movement::down, 5},
            {Movement::forward, 3},
            {Movement::down, 5},
            {Movement::down, 6},
            {Movement::down, 7},
            {Movement::down, 3},
            {Movement::down, 8},
            {Movement::up, 5},
            {Movement::forward, 2},
            {Movement::forward, 5},
            {Movement::up, 7},
            {Movement::up, 4},
            {Movement::forward, 1},
            {Movement::forward, 1},
            {Movement::down, 1},
            {Movement::down, 7},
            {Movement::forward, 4},
            {Movement::up, 8},
            {Movement::forward, 5},
            {Movement::down, 9},
            {Movement::up, 7},
            {Movement::forward, 8},
            {Movement::down, 4},
            {Movement::forward, 4},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::forward, 7},
            {Movement::down, 1},
            {Movement::forward, 9},
            {Movement::down, 9},
            {Movement::up, 1},
            {Movement::down, 6},
            {Movement::forward, 6},
            {Movement::down, 7},
            {Movement::down, 4},
            {Movement::forward, 6},
            {Movement::forward, 3},
            {Movement::down, 5},
            {Movement::up, 5},
            {Movement::up, 7},
            {Movement::up, 5},
            {Movement::down, 6},
            {Movement::forward, 7},
            {Movement::up, 3},
            {Movement::down, 2},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::down, 7},
            {Movement::up, 9},
            {Movement::forward, 3},
            {Movement::forward, 1},
            {Movement::down, 8},
            {Movement::forward, 6},
            {Movement::forward, 4},
            {Movement::up, 9},
            {Movement::forward, 3},
            {Movement::down, 1},
            {Movement::forward, 4},
            {Movement::forward, 9},
            {Movement::forward, 2},
            {Movement::forward, 8},
            {Movement::forward, 1},
            {Movement::forward, 2},
            {Movement::forward, 7},
            {Movement::down, 6},
            {Movement::forward, 6},
            {Movement::up, 2},
            {Movement::forward, 5},
            {Movement::up, 8},
            {Movement::down, 9},
            {Movement::up, 8},
            {Movement::down, 5},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::up, 4},
            {Movement::down, 4},
            {Movement::down, 5},
            {Movement::up, 6},
            {Movement::down, 8},
            {Movement::down, 8},
            {Movement::forward, 9},
            {Movement::forward, 8},
            {Movement::forward, 2},
            {Movement::down, 2},
            {Movement::up, 3},
            {Movement::forward, 2},
            {Movement::down, 8},
            {Movement::down, 8},
            {Movement::forward, 3},
            {Movement::forward, 5},
            {Movement::down, 9},
            {Movement::down, 2},
            {Movement::forward, 6},
            {Movement::forward, 7},
            {Movement::down, 7},
            {Movement::forward, 4},
            {Movement::forward, 2},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::up, 5},
            {Movement::down, 2},
            {Movement::forward, 3},
            {Movement::forward, 9},
            {Movement::down, 9},
            {Movement::down, 3},
            {Movement::forward, 3},
            {Movement::forward, 6},
            {Movement::down, 2},
            {Movement::forward, 5},
            {Movement::forward, 7},
            {Movement::down, 6},
            {Movement::forward, 4},
            {Movement::down, 6},
            {Movement::forward, 6},
            {Movement::forward, 3},
            {Movement::forward, 3},
            {Movement::forward, 8},
            {Movement::down, 4},
            {Movement::up, 4},
            {Movement::down, 6},
            {Movement::down, 4},
            {Movement::down, 9},
            {Movement::forward, 7},
            {Movement::forward, 4},
            {Movement::forward, 7},
            {Movement::down, 3},
            {Movement::forward, 1},
            {Movement::down, 7},
            {Movement::down, 3},
            {Movement::forward, 1},
            {Movement::down, 7},
            {Movement::down, 5},
            {Movement::forward, 6},
            {Movement::up, 7},
            {Movement::down, 7},
            {Movement::forward, 5},
            {Movement::forward, 5},
            {Movement::up, 9},
            {Movement::down, 7},
            {Movement::forward, 1},
            {Movement::forward, 2},
            {Movement::down, 4},
            {Movement::down, 8},
            {Movement::down, 7},
            {Movement::forward, 4},
            {Movement::forward, 4},
            {Movement::forward, 3},
            {Movement::down, 8},
            {Movement::down, 7},
            {Movement::down, 8},
            {Movement::forward, 2},
            {Movement::down, 2},
            {Movement::forward, 2},
            {Movement::forward, 4},
            {Movement::up, 6},
            {Movement::down, 4},
            {Movement::up, 3},
            {Movement::forward, 7},
            {Movement::down, 9},
            {Movement::down, 3},
            {Movement::forward, 3},
            {Movement::down, 2},
            {Movement::down, 2},
            {Movement::up, 5},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::forward, 3},
            {Movement::up, 7},
            {Movement::forward, 8},
            {Movement::forward, 6},
            {Movement::down, 3},
            {Movement::forward, 2},
            {Movement::down, 6},
            {Movement::up, 1},
            {Movement::down, 7},
            {Movement::down, 7},
            {Movement::forward, 8},
            {Movement::up, 1},
            {Movement::up, 8},
            {Movement::up, 4},
            {Movement::up, 1},
            {Movement::forward, 4},
            {Movement::forward, 9},
            {Movement::down, 9},
            {Movement::down, 5},
            {Movement::down, 3},
            {Movement::forward, 8},
            {Movement::down, 3},
            {Movement::forward, 4},
            {Movement::down, 6},
            {Movement::down, 9},
            {Movement::down, 3},
            {Movement::forward, 6},
            {Movement::up, 1},
            {Movement::up, 4},
            {Movement::forward, 9},
            {Movement::down, 3},
            {Movement::up, 1},
            {Movement::forward, 4},
            {Movement::up, 1},
            {Movement::forward, 8},
            {Movement::down, 9},
            {Movement::up, 1},
            {Movement::forward, 3},
            {Movement::down, 7},
            {Movement::down, 7},
            {Movement::down, 3},
            {Movement::forward, 7},
            {Movement::forward, 5},
            {Movement::down, 8},
            {Movement::up, 8},
            {Movement::down, 6},
            {Movement::down, 4},
            {Movement::forward, 9},
            {Movement::down, 9},
            {Movement::up, 5},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::up, 8},
            {Movement::down, 2},
            {Movement::forward, 1},
            {Movement::down, 8},
            {Movement::down, 2},
            {Movement::forward, 7},
            {Movement::forward, 2},
            {Movement::down, 2},
            {Movement::forward, 5},
            {Movement::up, 2},
            {Movement::down, 6},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::down, 3},
            {Movement::up, 4},
            {Movement::forward, 4},
            {Movement::forward, 8},
            {Movement::down, 3},
            {Movement::forward, 9},
            {Movement::forward, 6},
            {Movement::down, 2},
            {Movement::up, 2},
            {Movement::down, 2},
            {Movement::up, 4},
            {Movement::down, 8},
            {Movement::forward, 5},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::down, 4},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::down, 2},
            {Movement::up, 7},
            {Movement::down, 3},
            {Movement::down, 6},
            {Movement::up, 1},
            {Movement::forward, 8},
            {Movement::up, 5},
            {Movement::down, 1},
            {Movement::forward, 3},
            {Movement::down, 2},
            {Movement::down, 5},
            {Movement::up, 5},
            {Movement::up, 2},
            {Movement::down, 2},
            {Movement::down, 2},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::up, 7},
            {Movement::forward, 8},
            {Movement::forward, 4},
            {Movement::down, 3},
            {Movement::forward, 8},
            {Movement::down, 4},
            {Movement::down, 9},
            {Movement::down, 7},
            {Movement::up, 3},
            {Movement::up, 4},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::down, 3},
            {Movement::up, 5},
            {Movement::down, 1},
            {Movement::forward, 4},
            {Movement::forward, 9},
            {Movement::forward, 3},
            {Movement::forward, 3},
            {Movement::up, 6},
            {Movement::down, 3},
            {Movement::forward, 3},
            {Movement::up, 7},
            {Movement::down, 3},
            {Movement::up, 7},
            {Movement::up, 2},
            {Movement::up, 2},
            {Movement::down, 9},
            {Movement::forward, 4},
            {Movement::forward, 7},
            {Movement::forward, 7},
            {Movement::down, 7},
            {Movement::forward, 2},
            {Movement::forward, 1},
            {Movement::down, 9},
            {Movement::forward, 2},
            {Movement::down, 2},
            {Movement::down, 4},
            {Movement::up, 3},
            {Movement::forward, 8},
            {Movement::up, 3},
            {Movement::down, 7},
            {Movement::forward, 9},
            {Movement::down, 7},
            {Movement::forward, 2},
            {Movement::down, 1},
            {Movement::up, 9},
            {Movement::forward, 7},
            {Movement::forward, 9},
            {Movement::up, 4},
            {Movement::forward, 3},
            {Movement::forward, 1},
            {Movement::down, 5},
            {Movement::down, 6},
            {Movement::forward, 9},
            {Movement::down, 9},
            {Movement::forward, 2},
            {Movement::forward, 8},
            {Movement::forward, 4},
            {Movement::forward, 9},
            {Movement::down, 5},
            {Movement::down, 9},
            {Movement::down, 3},
            {Movement::down, 7},
            {Movement::up, 2},
            {Movement::up, 7},
            {Movement::forward, 6},
            {Movement::down, 3},
            {Movement::down, 2},
            {Movement::up, 1},
            {Movement::forward, 4},
            {Movement::down, 1},
            {Movement::up, 4},
            {Movement::up, 8},
            {Movement::down, 9},
            {Movement::down, 5},
            {Movement::down, 7},
            {Movement::forward, 4},
            {Movement::down, 1},
            {Movement::forward, 8},
            {Movement::down, 5},
            {Movement::forward, 7},
            {Movement::down, 3},
            {Movement::up, 2},
            {Movement::forward, 4},
            {Movement::down, 1},
            {Movement::forward, 4},
            {Movement::up, 5},
            {Movement::forward, 9},
            {Movement::down, 1},
            {Movement::forward, 7},
            {Movement::up, 3},
            {Movement::up, 9},
            {Movement::forward, 4},
            {Movement::up, 5},
            {Movement::down, 6},
            {Movement::forward, 2},
            {Movement::down, 1},
            {Movement::forward, 1},
            {Movement::down, 9},
            {Movement::forward, 5},
            {Movement::down, 2},
            {Movement::up, 3},
            {Movement::down, 5},
            {Movement::up, 4},
            {Movement::down, 5},
            {Movement::down, 8},
            {Movement::down, 8},
            {Movement::down, 3},
            {Movement::forward, 9},
            {Movement::forward, 2},
            {Movement::down, 3},
            {Movement::down, 3},
            {Movement::down, 6},
            {Movement::down, 8},
            {Movement::forward, 9},
            {Movement::down, 4},
            {Movement::down, 1},
            {Movement::forward, 4},
            {Movement::down, 9},
            {Movement::forward, 1},
            {Movement::down, 9},
            {Movement::up, 6},
            {Movement::up, 7},
            {Movement::up, 8},
            {Movement::forward, 5},
            {Movement::down, 3},
            {Movement::up, 5},
            {Movement::up, 1},
            {Movement::down, 8},
            {Movement::forward, 1},
            {Movement::forward, 7},
            {Movement::up, 9},
            {Movement::down, 7},
            {Movement::forward, 4},
            {Movement::down, 5},
            {Movement::forward, 2},
            {Movement::down, 6},
            {Movement::up, 8},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::down, 9},
            {Movement::down, 8},
            {Movement::forward, 8},
            {Movement::down, 4},
            {Movement::up, 2},
            {Movement::down, 2},
            {Movement::forward, 9},
            {Movement::up, 6},
            {Movement::down, 3},
            {Movement::forward, 5},
            {Movement::forward, 9},
            {Movement::up, 2},
            {Movement::up, 5},
            {Movement::down, 5},
            {Movement::forward, 2},
            {Movement::forward, 3},
            {Movement::forward, 2},
            {Movement::up, 2},
            {Movement::down, 2},
            {Movement::forward, 9},
            {Movement::up, 4},
            {Movement::down, 4},
            {Movement::up, 1},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::down, 6},
            {Movement::forward, 2},
            {Movement::up, 6},
            {Movement::up, 9},
            {Movement::forward, 7},
            {Movement::forward, 4},
            {Movement::down, 6},
            {Movement::down, 5},
            {Movement::down, 5},
            {Movement::down, 9},
            {Movement::forward, 7},
            {Movement::down, 1},
            {Movement::up, 5},
            {Movement::forward, 4},
            {Movement::up, 8},
            {Movement::up, 8},
            {Movement::down, 4},
            {Movement::down, 7},
            {Movement::forward, 1},
            {Movement::forward, 8},
            {Movement::down, 3},
            {Movement::up, 3},
            {Movement::up, 3},
            {Movement::up, 4},
            {Movement::down, 1},
            {Movement::down, 8},
            {Movement::up, 6},
            {Movement::up, 8},
            {Movement::forward, 2},
            {Movement::down, 2},
            {Movement::down, 3},
            {Movement::forward, 4},
            {Movement::forward, 3},
            {Movement::forward, 6},
            {Movement::down, 1},
            {Movement::up, 6},
            {Movement::forward, 2},
            {Movement::forward, 6},
            {Movement::forward, 2},
            {Movement::forward, 5},
            {Movement::down, 1},
            {Movement::up, 4},
            {Movement::forward, 7},
            {Movement::down, 6},
            {Movement::forward, 8},
            {Movement::up, 9},
            {Movement::down, 5},
            {Movement::up, 3},
            {Movement::forward, 8},
            {Movement::forward, 1},
            {Movement::forward, 9},
            {Movement::up, 9},
            {Movement::forward, 4},
            {Movement::forward, 5},
            {Movement::down, 1},
            {Movement::up, 9},
            {Movement::down, 5},
            {Movement::down, 7},
            {Movement::forward, 8},
            {Movement::down, 1},
            {Movement::forward, 3},
            {Movement::forward, 2},
            {Movement::down, 9},
            {Movement::down, 1},
            {Movement::forward, 5},
            {Movement::up, 6},
            {Movement::down, 7},
            {Movement::forward, 4},
            {Movement::down, 6},
            {Movement::forward, 1},
            {Movement::forward, 8},
            {Movement::up, 4},
            {Movement::forward, 5},
            {Movement::down, 8},
            {Movement::forward, 6},
            {Movement::up, 2},
            {Movement::forward, 3},
            {Movement::forward, 5},
            {Movement::up, 6},
            {Movement::up, 8},
            {Movement::up, 4},
            {Movement::forward, 6},
            {Movement::down, 2},
            {Movement::down, 6},
            {Movement::down, 5},
            {Movement::up, 2},
            {Movement::down, 3},
            {Movement::down, 7},
            {Movement::up, 6},
            {Movement::forward, 2},
            {Movement::forward, 3},
            {Movement::up, 6},
            {Movement::forward, 3},
            {Movement::up, 8},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::down, 7},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::up, 8},
            {Movement::up, 9},
            {Movement::down, 4},
            {Movement::forward, 2},
            {Movement::forward, 7},
            {Movement::down, 8},
            {Movement::up, 6},
            {Movement::up, 8},
            {Movement::up, 8},
            {Movement::down, 4},
            {Movement::forward, 9},
            {Movement::down, 5},
            {Movement::forward, 5},
            {Movement::forward, 3},
            {Movement::down, 1},
            {Movement::forward, 1},
            {Movement::up, 9},
            {Movement::down, 1},
            {Movement::down, 6},
            {Movement::up, 6},
            {Movement::forward, 7},
            {Movement::forward, 1},
            {Movement::down, 5},
            {Movement::down, 2},
            {Movement::forward, 5},
            {Movement::down, 3},
            {Movement::down, 4},
            {Movement::forward, 6},
            {Movement::up, 6},
            {Movement::down, 9},
            {Movement::up, 3},
            {Movement::forward, 1},
            {Movement::up, 3},
            {Movement::down, 5},
            {Movement::up, 4},
            {Movement::down, 4},
            {Movement::forward, 9},
            {Movement::up, 5},
            {Movement::down, 1},
            {Movement::forward, 4},
            {Movement::down, 8},
            {Movement::up, 1},
            {Movement::forward, 9},
            {Movement::forward, 8},
            {Movement::up, 4},
            {Movement::up, 3},
            {Movement::up, 5},
            {Movement::forward, 5},
            {Movement::up, 7},
            {Movement::forward, 5},
            {Movement::forward, 4},
            {Movement::forward, 6},
            {Movement::forward, 9},
            {Movement::down, 6},
            {Movement::down, 3},
            {Movement::up, 5},
            {Movement::forward, 2},
            {Movement::up, 9},
            {Movement::down, 4},
            {Movement::down, 2},
            {Movement::forward, 5},
            {Movement::up, 6},
            {Movement::forward, 1},
            {Movement::up, 5},
            {Movement::up, 3},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::forward, 6},
            {Movement::up, 4},
            {Movement::up, 6},
            {Movement::down, 3},
            {Movement::down, 2},
            {Movement::up, 3},
            {Movement::down, 9},
            {Movement::up, 7},
            {Movement::forward, 6},
            {Movement::up, 4},
            {Movement::forward, 7},
            {Movement::down, 4},
            {Movement::up, 6},
            {Movement::down, 6},
            {Movement::forward, 9},
            {Movement::forward, 4},
            {Movement::up, 2},
            {Movement::forward, 7},
            {Movement::up, 5},
            {Movement::forward, 2},
            {Movement::forward, 2},
            {Movement::down, 4},
            {Movement::down, 4},
            {Movement::forward, 3},
            {Movement::down, 4},
            {Movement::up, 3},
            {Movement::forward, 9},
            {Movement::down, 5},
            {Movement::forward, 6},
            {Movement::forward, 9},
            {Movement::forward, 9},
            {Movement::up, 6},
            {Movement::down, 9},
            {Movement::forward, 8},
            {Movement::up, 7},
            {Movement::up, 5},
            {Movement::down, 6},
            {Movement::forward, 6},
            {Movement::forward, 1},
            {Movement::down, 6},
            {Movement::forward, 5},
            {Movement::down, 2},
            {Movement::down, 1},
            {Movement::forward, 6},
            {Movement::down, 6},
            {Movement::down, 9},
            {Movement::down, 5},
            {Movement::forward, 1},
            {Movement::down, 7},
            {Movement::down, 7},
            {Movement::down, 4},
            {Movement::forward, 7},
            {Movement::up, 5},
            {Movement::up, 1},
            {Movement::up, 2},
            {Movement::up, 5},
            {Movement::down, 3},
            {Movement::forward, 9},
            {Movement::forward, 2},
            {Movement::forward, 8},
            {Movement::up, 4},
            {Movement::forward, 7},
            {Movement::forward, 6},
            {Movement::forward, 9},
            {Movement::down, 2},
            {Movement::down, 6},
            {Movement::forward, 4},
            {Movement::down, 9},
            {Movement::down, 9},
            {Movement::up, 3},
            {Movement::forward, 2},
            {Movement::forward, 1},
            {Movement::down, 5},
            {Movement::up, 9},
            {Movement::down, 6},
            {Movement::forward, 6},
            {Movement::down, 8},
            {Movement::forward, 3},
            {Movement::forward, 5},
            {Movement::forward, 3},
            {Movement::forward, 2},
            {Movement::down, 7},
            {Movement::down, 2},
            {Movement::up, 8},
            {Movement::forward, 9},
            {Movement::down, 8},
            {Movement::up, 7},
            {Movement::down, 4},
            {Movement::up, 3},
            {Movement::forward, 6},
            {Movement::down, 3},
            {Movement::up, 3},
            {Movement::down, 6},
            {Movement::down, 3},
            {Movement::up, 2},
            {Movement::down, 4},
            {Movement::down, 4},
            {Movement::up, 2},
            {Movement::down, 6},
            {Movement::down, 5},
            {Movement::down, 9},
            {Movement::down, 1},
            {Movement::down, 7},
            {Movement::up, 9},
            {Movement::down, 4},
            {Movement::up, 6},
            {Movement::down, 6},
            {Movement::forward, 9},
            {Movement::forward, 2},
            {Movement::down, 8},
            {Movement::down, 3},
            {Movement::forward, 4},
            {Movement::forward, 4},
            {Movement::forward, 5},
            {Movement::down, 2},
            {Movement::down, 8},
            {Movement::down, 1},
            {Movement::up, 4},
            {Movement::forward, 9},
            {Movement::up, 7},
            {Movement::forward, 5},
            {Movement::down, 5},
            {Movement::up, 9},
            {Movement::down, 2},
            {Movement::down, 2},
            {Movement::forward, 4},
            {Movement::forward, 4},
            {Movement::forward, 8},
    };

    std::printf("- Part I -\n");
    run_submarine(commands, Action::increase_horizontal_position, Action::increase_depth, Action::decrease_depth);
    std::printf("\n- Part II -\n");
    run_submarine(commands, Action::increase_position_and_depth, Action::increase_aim, Action::decrease_aim);
}