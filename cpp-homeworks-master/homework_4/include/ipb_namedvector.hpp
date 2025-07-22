#pragma once
#include <iostream>
#include <vector>

namespace ipb {
template <typename T>
struct named_vector {
    std::string vname;
    std::vector<T> v;

    auto resize(int num) { return v.resize(num); }
    auto reserve(int num) { return v.reserve(num); }
    auto capacity() { return v.capacity(); }
    auto size() { return v.size() + vname.size(); }
    auto vector() { return v; }
    auto name() { return vname; }
    auto empty() { return (vname.empty()) || (v.empty()); }
};
}  // namespace ipb