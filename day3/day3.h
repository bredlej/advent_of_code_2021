//
// Created by geoco on 03.12.2021.
//
#ifndef ADVENT_OF_CODE_2021_DAY3_H
#define ADVENT_OF_CODE_2021_DAY3_H
#include <array>
#include <bitset>
#include <cassert>
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

template<typename T, size_t N, typename Functor>
struct processor {
    void run(const std::vector<std::string> &input);
    [[nodiscard]] T gamma() const;
    [[nodiscard]] T epsilon() const;
    [[nodiscard]] T power_consumption()const ;
    std::array<Functor, N> msb_array;
    std::array<Functor, N> feed_data(const std::string &bits) const;
};

template<typename T, size_t N, typename Functor>
std::array<Functor, N> processor<T, N, Functor>::feed_data(const std::string &bits) const{
    assert(bits.length() == N);

    std::array<Functor, N> replacement;
    std::bitset<N> bits_of{bits};
    for (int i = 0; i < N; i++) {
        replacement[i] = msb_array[i](bits_of[i]);
    }
    return replacement;
}

template<typename T, size_t N, typename Functor>
void processor<T, N, Functor>::run(const std::vector<std::string> &input) {
    for (auto &data: input) {
        msb_array = feed_data(data);
    }
}

template<typename T, size_t N, typename Functor>
T processor<T, N, Functor>::gamma() const{
    std::bitset<N> bits;
    for (int i =0; i < N; i++) {
        assert(msb_array[i].yield() != -1);
        bits[i] = msb_array[i].yield();
    }
    return bits.to_ulong();
}

template<typename T, size_t N, typename Functor>
T processor<T, N, Functor>::epsilon() const{
    std::bitset<N> bits;
    for (int i =0; i < N; i++) {
        assert(msb_array[i].yield() != -1);
        bits[i] = !msb_array[i].yield();
    }
    return bits.to_ulong();
}

template<typename T, size_t N, typename Functor>
T processor<T, N, Functor>::power_consumption() const {
    return gamma() * epsilon();
}
#endif//ADVENT_OF_CODE_2021_DAY3_H
