//
// Created by geoco on 03.12.2021.
//
#include <day3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cstdio>
#include <tuple>

std::vector<std::string> import_data(const std::string &filename) {
    std::vector<std::string> input;
    std::ifstream in(filename.c_str());
    if (!in) {
        printf("Can't open the file\n");
    }
    std::string content_line;
    while(std::getline(in, content_line)) {
        input.push_back(content_line);
    }
    in.close();
    return input;
};

int main() {
    const auto input = import_data("inputfile");
    auto before = std::chrono::high_resolution_clock::now();
    processor<uint32_t, 12, most_common_bit> p;
    p.run(input);
    auto [gamma, epsilon, power] = std::make_tuple<>(p.gamma(), p.epsilon(), p.power_consumption());
    auto after = std::chrono::high_resolution_clock::now() - before;
    std::printf("Elapsed time: %lld microseconds\n", std::chrono::duration_cast<std::chrono::microseconds>(after).count());
    std::printf("Gamma=[%d], Epsilon=[%d], Power consumption=[%d]\n", gamma, epsilon, power);
    return 0;
}
