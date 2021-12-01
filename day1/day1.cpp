//
// Created by geoco on 01.12.2021.
//

#include "day1.h"
#include <chrono>
#include <iterator>

constexpr auto group_data = [] (const uint32_t amount, const std::vector<uint32_t> &data) {
    auto remaining_size = data.size();
    auto iterator = data.begin();
    std::vector<uint32_t> result_data;
    while (remaining_size >= amount) {
        uint32_t sum = *iterator;
        for (uint32_t i = 1; i < amount; i++) {
            sum += *std::next(iterator, i);
        }
        result_data.push_back(sum);
        remaining_size--;
        ++iterator;
    }
    return result_data;
};

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

static const std::vector<uint32_t> test_input = {199,
                                                 200,
                                                 208,
                                                 210,
                                                 200,
                                                 207,
                                                 240,
                                                 269,
                                                 260,
                                                 263};
int main() {
    auto before = std::chrono::high_resolution_clock::now();
    uint32_t depth_increases;
    depth_increases = count_depth_increase(group_data(3, input));

    auto after = std::chrono::high_resolution_clock::now() - before;
    std::printf("Counted %d in %lld microseconds", depth_increases, std::chrono::duration_cast<std::chrono::microseconds>(after).count());
    return 0;
}