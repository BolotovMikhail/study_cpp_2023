#pragma once

#include "helpers.h"

void ReverseLexicographicallySort(ip_pool& ipTuples);
void ReverseLexicographicallySort(ip_pool& ipTuples)
{
    std::sort(ipTuples.begin(), ipTuples.end(), std::greater<ip_tuple>());
}

ip_pool FilterIpPool(const ip_pool& IpPool, const ip_tuple& Filter);
ip_pool FilterIpPool(const ip_pool& IpPool, const ip_tuple& Filter)
{
    ip_pool filteredIpPool;

    for (const auto& Ip : IpPool)
    {
        if ((std::get<0>(Filter) == AnyByte ||
                std::get<0>(Ip) == std::get<0>(Filter)) &&
            (std::get<1>(Filter) == AnyByte ||
                std::get<1>(Ip) == std::get<1>(Filter)) &&
            (std::get<2>(Filter) == AnyByte ||
                std::get<2>(Ip) == std::get<2>(Filter)) &&
            (std::get<3>(Filter) == AnyByte ||
                std::get<3>(Ip) == std::get<3>(Filter)))
        {
            filteredIpPool.emplace_back(Ip);
        }
    }

    return std::move(filteredIpPool);
}

ip_pool FilterIpPoolByAny(const ip_pool& IpPool, const unsigned int value);
ip_pool FilterIpPoolByAny(const ip_pool& IpPool, const unsigned int value)
{
    ip_pool filteredIpPool;

    for (const auto& Ip : IpPool)
    {
        if (std::get<0>(Ip) == value ||
            std::get<1>(Ip) == value ||
            std::get<2>(Ip) == value ||
            std::get<3>(Ip) == value)
        {
            filteredIpPool.emplace_back(Ip);
        }
    }

    return std::move(filteredIpPool);
}
