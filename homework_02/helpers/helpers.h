#pragma once

#include <iostream>
#include <tuple>
#include <vector>

using ip_tuple = std::tuple<int, int, int, int>;
using ip_pool = std::vector<ip_tuple>;

constexpr auto AnyByte{-1};

void PrintIpPool(const ip_pool& IpPool);
void PrintIpPool(const ip_pool& IpPool)
{
    for (const auto& Ip : IpPool)
    {
        std::cout << std::get<0>(Ip) << "." \
            << std::get<1>(Ip) << "." \
            << std::get<2>(Ip) << "." \
            << std::get<3>(Ip) << '\n';
    }
}
