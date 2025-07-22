#pragma once
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// #include "homework_4.h"
#include "ipb_namedvector.hpp"

namespace ipb {
template <typename T>
auto accumulate(named_vector<T> v) {
    return std::accumulate(v.v.begin(), v.v.end(), 0);
}
template <typename T>
auto count(named_vector<T> v, T num2cnt) {
    return std::count(v.v.begin(), v.v.end(), num2cnt);
}

template <typename T>
auto find(named_vector<T>& v, T num2find) {
    return (std::find(v.v.begin(), v.v.end(), num2find) !=
            std::end(v.vector()));
}

template <typename T>
auto fill(named_vector<T>& v, T num2fill) {
    std::fill(v.v.begin(), v.v.end(), num2fill);
}

template <typename T>
auto clamp(named_vector<T>& v, T min, T max) {
    std::transform(v.v.begin(), v.v.end(), v.v.begin(),
                   [&](const T& i) { return std::clamp(i, min, max); });
}

template <typename T>
auto rotate(named_vector<T>& v, int rotateby) {
    std::rotate(v.v.begin(), v.v.begin() + rotateby, v.v.end());
}

template <typename T>
auto sort(named_vector<T>& v) {
    std::sort(v.v.begin(), v.v.end());
}

template <typename T>
auto reverse(named_vector<T>& v) {
    std::reverse(v.v.begin(), v.v.end());
}

template <typename T>
auto toupper(named_vector<T>& v) {
    std::transform(v.vname.begin(), v.vname.end(), v.vname.begin(), ::toupper);
}

template <typename T>
auto all_even(named_vector<T> v) {
    auto result = std::all_of(v.vector().begin(), v.vector().end(),
                              [](T i) { return i % 2 == 0; });

    return result;
}
template <typename T>
auto print(named_vector<T> v) {
    std::cout << v.name() << " : ";
    std::cout << "{";
    for (const auto& elem : v.vector()) {
        std::cout << elem << " ";
    }
    std::cout << "}";
}
}  // namespace ipb
