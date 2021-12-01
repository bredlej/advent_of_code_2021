//
// Created by geoco on 01.12.2021.
//

#include "day1.h"
#include <chrono>

constexpr auto count_depth_increase = [] (const std::vector<uint32_t> &data) {
    uint32_t counter = 0;
    uint32_t last_depth = data.front();
    for (auto depth: data) {
        if (depth > last_depth) {
            counter++;
        }
        last_depth = depth;
    }
    return counter;
};

int main() {
    auto before = std::chrono::high_resolution_clock::now();
    uint32_t depth_increases;
    for (int i = 0; i < 1000; i++) {
        depth_increases = count_depth_increase(input);
    }
    auto after = std::chrono::high_resolution_clock::now() - before;
    std::printf("Counted %d in %lld microseconds", depth_increases, std::chrono::duration_cast<std::chrono::microseconds>(after).count());
    return 0;
}