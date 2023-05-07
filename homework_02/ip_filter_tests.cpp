
#include <gtest/gtest.h>

#include "filters.h"

class IpFilter : public ::testing::Test
{
protected:
    void SetUp()
    { }

    void TearDown()
    { }

    ip_pool ipPool = {
        {7, 15, 27, 255},
        {19, 2, 6, 98},
        {3, 255, 255, 255},
        {8, 8, 9, 9},
        {1, 1, 1, 1},
        {127, 255, 255, 255},
        {2, 7, 8, 4},
        {2, 7, 5, 9},
        {2, 3, 2, 255},
        {2, 7, 8, 3},
        {2, 7, 8, 3}
    };

    static constexpr int Byte2{2};
    static constexpr int Byte7{7};
    static constexpr int Byte8{8};
    static constexpr int Byte3{3};
    static constexpr int IncorrectByte{99851};
    static constexpr int AnyOneByte{255};
};

TEST_F(IpFilter, ReverseLexicographicallySortSuccess)
{
    const ip_pool ExpectedIpPool = {
        {127, 255, 255, 255},
        {19, 2, 6, 98},
        {8, 8, 9, 9},
        {7, 15, 27, 255},
        {3, 255, 255, 255},
        {2, 7, 8, 4},
        {2, 7, 8, 3},
        {2, 7, 8, 3},
        {2, 7, 5, 9},
        {2, 3, 2, 255},
        {1, 1, 1, 1}
    };

    ReverseLexicographicallySort(ipPool);

    ASSERT_EQ(ipPool, ExpectedIpPool);
}

TEST_F(IpFilter, FilterIpPoolByFirstByteSuccess)
{
    constexpr ip_array FilterByFirstByte{
        Byte2, AnyByte, AnyByte, AnyByte};

    const ip_pool ExpectedIpPool = {
        {2, 7, 8, 4},
        {2, 7, 5, 9},
        {2, 3, 2, 255},
        {2, 7, 8, 3},
        {2, 7, 8, 3}
  };

    const auto FilteredByFirstByte = FilterIpPool(
        ipPool, FilterByFirstByte);

    ASSERT_EQ(FilteredByFirstByte, ExpectedIpPool);
}

TEST_F(IpFilter, FilterEmptyIpPoolSuccess)
{
    constexpr ip_array FilterByFirstByte{
        Byte2, AnyByte, AnyByte, AnyByte};

    const ip_pool EmptyIpPool = {};
    const ip_pool ExpectedIpPool = EmptyIpPool;

    const auto FilteredEmptyIpPool = FilterIpPool(
        EmptyIpPool, FilterByFirstByte);

    ASSERT_EQ(FilteredEmptyIpPool, ExpectedIpPool);
}

TEST_F(IpFilter, FilterIpPoolByAllBytesSuccess)
{
    constexpr ip_array FilterByAllBytes{
        Byte2, Byte7, Byte8, Byte3};
    
    const ip_pool ExpectedIpPool = {
        {2, 7, 8, 3},
        {2, 7, 8, 3}
    };

    const auto FilteredByAllBytes = FilterIpPool(
        ipPool, FilterByAllBytes);
    
    ASSERT_EQ(FilteredByAllBytes, ExpectedIpPool);
}

TEST_F(IpFilter, FilterIpPoolByAnyBytesSuccess)
{
    constexpr ip_array FilterByAnyBytes{
        AnyByte, AnyByte, AnyByte, AnyByte};
    
    const ip_pool ExpectedIpPool = ipPool;

    const auto FilteredByAnyBytes = FilterIpPool(
        ipPool, FilterByAnyBytes);
    
    ASSERT_EQ(FilteredByAnyBytes, ExpectedIpPool);
}

TEST_F(IpFilter, FilterIpPoolByIncorrectBytesSuccess)
{
    constexpr ip_array FilterByIncorrectBytes{
        IncorrectByte, AnyByte, IncorrectByte, AnyByte};
    
    const ip_pool ExpectedIpPool = {};

    const auto FilteredByIncorrectBytes = FilterIpPool(
        ipPool, FilterByIncorrectBytes);
    
    ASSERT_EQ(FilteredByIncorrectBytes, ExpectedIpPool);
}

TEST_F(IpFilter, FilterIpPoolByAnyOneByteSuccess)
{
    const ip_pool ExpectedIpPool = {
        {7, 15, 27, 255},
        {3, 255, 255, 255},
        {127, 255, 255, 255},
        {2, 3, 2, 255},
    };

    const auto FilteredByAnyOneByte = FilterIpPoolByAny(
        ipPool, AnyOneByte);

    ASSERT_EQ(FilteredByAnyOneByte, ExpectedIpPool);
}
