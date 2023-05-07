#pragma once

#include <iostream>
#include <array>
#include <vector>

using ip_array = std::array<int, 4>;
using ip_pool = std::vector<ip_array>;

constexpr auto AnyByte{-1};

inline void PrintIpPool(const ip_pool& IpPool)
{
    for (const auto& Ip : IpPool)
    {
        std::cout << Ip.at(0) << "." \
            << Ip.at(1) << "." \
            << Ip.at(2) << "." \
            << Ip.at(3) << '\n';
    }
}
