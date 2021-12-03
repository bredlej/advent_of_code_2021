//
// Created by geoco on 03.12.2021.
//
#ifndef ADVENT_OF_CODE_2021_DAY3_H
#define ADVENT_OF_CODE_2021_DAY3_H
#include <cstdint>
#include <vector>
#include <string>
#include <cassert>
#include <cstdio>
#include <bitset>

constexpr auto determine_bitsize_with_assertions = [](const std::vector<std::string> &values) {
    auto iterator = values.begin();
    auto size = iterator->length();
    for (const auto& it: values) {
        if (it.length() != size) { size = -1; }
    }
    return size;
};

uint64_t binary_to_decimal(const std::string &value) {
    return std::stoull(value, nullptr, 2);
}

#endif//ADVENT_OF_CODE_2021_DAY3_H
