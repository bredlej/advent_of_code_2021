//
// Created by geoco on 03.12.2021.
//
#ifndef ADVENT_OF_CODE_2021_DAY3_H
#define ADVENT_OF_CODE_2021_DAY3_H
#include <array>
#include <bitset>
#include <cassert>
#include <cppcoro/generator.hpp>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <string>
#include <vector>

constexpr auto yield_val = [](const auto zeroes, const auto ones) {
    if (zeroes > ones) { return 0; }
    else if (ones > zeroes) { return 1; }
    else { return -1; }
};

struct most_common_bit {
private:
    most_common_bit(const auto zeroes, const auto ones, const auto devnull) : zeroes{zeroes}, ones{ones} {};
    uint32_t zeroes = 0;
    uint32_t ones = 0;
public:
    most_common_bit() : zeroes{0}, ones{0} {};
    most_common_bit operator()(uint8_t bit) const {
        return most_common_bit{bit == 0 ? zeroes +1 : zeroes, bit == 1 ? ones + 1 : ones, 0};
    }
    most_common_bit operator()(uint8_t bit, most_common_bit &&mcb) const {
        return most_common_bit{bit == 0 ? mcb.zeroes +1 : mcb.zeroes, bit == 1 ? mcb.ones + 1 : mcb.ones, 0};
    }
    bool operator==(uint8_t other) const {
            return yield_val(zeroes, ones) == other;
    };
    [[nodiscard]] auto yield() const  {
        return yield_val(zeroes, ones);
    }
};


constexpr auto determine_bitsize_with_assertions = [](const std::vector<std::string> &values) {
    auto iterator = values.begin();
    auto size = iterator->length();
    for (const auto &it : values) {
        if (it.length() != size) { size = -1; }
    }
    return size;
};

uint64_t binary_to_decimal(const std::string &value) {
    return std::stoull(value, nullptr, 2);
}

template<int T>
std::array<most_common_bit, T> parse_input(const std::vector<std::string> &values) {
    return std::array<most_common_bit, T>();
}

#endif//ADVENT_OF_CODE_2021_DAY3_H
