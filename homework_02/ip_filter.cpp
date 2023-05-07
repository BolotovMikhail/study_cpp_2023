#include <regex>
#include <string>
#include <vector>

#include "filters.h"

const std::regex IpPattern(R"((\d{1,3})\.(\d{1,3})\.(\d{1,3})\.(\d{1,3}))");

namespace {
constexpr ip_array FilterByFirstByte{1, AnyByte, AnyByte, AnyByte};
constexpr ip_array FilterByFirstAndSecondByte{46, 70, AnyByte, AnyByte};
constexpr unsigned int Byte46{46};
}

int main()
{
    try
    {
        ip_pool ipPool;

        std::smatch matches;
        for(std::string line; std::getline(std::cin, line);)
        {
            std::regex_search(line, matches, IpPattern);
            ipPool.emplace_back(std::array<int, 4>{
                std::stoi(matches[1]),
                std::stoi(matches[2]),
                std::stoi(matches[3]),
                std::stoi(matches[4])});
        }

        // 1. all ip in reverse lexicographically sort
        ReverseLexicographicallySort(ipPool);
        PrintIpPool(ipPool);

        // 2. all ip in reverse lexicographically sort filtered by first byte == 1
        const auto FilteredByFirstByte = FilterIpPool(
            ipPool, FilterByFirstByte);
        PrintIpPool(FilteredByFirstByte);

        // 3. all ip in reverse lexicographically sort filtered by first byte == 46 and second == 70
        const auto FilteredByFirstAndSecondByte = FilterIpPool(
            ipPool, FilterByFirstAndSecondByte);
        PrintIpPool(FilteredByFirstAndSecondByte);

        // 4. all ip in reverse lexicographically sort filtered by any byte == 46
        const auto FilteredByAnyByte = FilterIpPoolByAny(
            ipPool, Byte46);
        PrintIpPool(FilteredByAnyByte);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
