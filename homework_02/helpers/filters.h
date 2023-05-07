#pragma once

#include "helpers.h"

inline void ReverseLexicographicallySort(ip_pool& ipTuples)
{
    std::sort(ipTuples.begin(), ipTuples.end(), std::greater<ip_array>());
}

inline ip_pool FilterIpPool(const ip_pool& IpPool, const ip_array& Filter)
{
    ip_pool filteredIpPool;

    for (const auto& Ip : IpPool)
    {
        if ((Filter.at(0) == AnyByte ||
                Ip.at(0) == Filter.at(0)) &&
            (Filter.at(1) == AnyByte ||
                Ip.at(1) == Filter.at(1)) &&
            (Filter.at(2) == AnyByte ||
                Ip.at(2) == Filter.at(2)) &&
            (Filter.at(3) == AnyByte ||
                Ip.at(3) == Filter.at(3)))
        {
            filteredIpPool.push_back(Ip);
        }
    }

    return filteredIpPool;
}

inline ip_pool FilterIpPoolByAny(const ip_pool& IpPool, const int Value)
{
    ip_pool filteredIpPool;

    for (const auto& Ip : IpPool)
    {
        if (Ip.at(0) == Value ||
            Ip.at(1) == Value ||
            Ip.at(2) == Value ||
            Ip.at(3) == Value)
        {
            filteredIpPool.push_back(Ip);
        }
    }

    return filteredIpPool;
}
