#pragma once
#include <random>

namespace Utils
{
    template <typename T>
    const T GET_RANDOM_NUMBER(T min, T max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        if constexpr (std::is_integral<T>::value) {
            std::uniform_int_distribution<T> dist(min, max);
            return dist(gen);
        }
        else {
            std::uniform_real_distribution<T> dist(min, max);
            return dist(gen);
        }
    }
}