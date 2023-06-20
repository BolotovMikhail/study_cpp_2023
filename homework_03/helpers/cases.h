#ifndef HELPERS_CASES_H
#define HELPERS_CASES_H

#include <array>

#include "allocators.h"
#include "custom_container.h"

namespace {
    constexpr auto MaxCount{10};
} // anonymous namespace

inline int Factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * Factorial(n-1);
}

inline void MapWithCustomAllocatorCase()
{
    std::cout << "=======================================\n"
    << "First case: create std::map<int, int>, \n\
with custom allocator and fill it:" << "\n";

    {
        custom::map<int, int, MaxCount> mapWithCustomAllocator;
        for (int i{0}; i < MaxCount; ++i)
        {
            mapWithCustomAllocator.insert({i, Factorial(i)});
        }

        for (const auto& [key, value] : mapWithCustomAllocator)
        {
            std::cout << "Key: " << key << ", Value: " << value << "\n";
        }
    }

    {
        map_pool_allocator<int, 10> alloc;
        auto a =  alloc.allocate(1);
        auto b =  alloc.allocate(1);
        alloc.deallocate(a, 1);
        *b = 42;
    }
}

inline void CustomContainerCase()
{
    std::cout << "=======================================\n"
    << "Second case: create CustomContainer, \n\
with custom allocator and fill it:" << "\n";

    using container_with_allocator = SimpleCustomContainer<custom_container_pool_allocator<int, MaxCount>>;

    {
        {
            auto simpleCustomContainer = SimpleCustomContainer{Factorial(0)};
            simpleCustomContainer.PrintData();
            for (auto i{1}; i < MaxCount; ++i)
            {
                simpleCustomContainer.PushBack(Factorial(i));
                simpleCustomContainer.PrintData();
            }
        }
        std::cout << "=======================================\n";
        {
            container_with_allocator simpleCustomContainer = container_with_allocator{Factorial(0)};
            simpleCustomContainer.PrintData();
            for (auto i{1}; i < MaxCount; ++i)
            {
                simpleCustomContainer.PushBack(Factorial(i));
                simpleCustomContainer.PrintData();
            }
        }
    }

    std::cout << "=======================================\n";
}


#endif // HELPERS_CASES_H
