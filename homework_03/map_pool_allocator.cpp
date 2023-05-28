#include <iostream>
#include <map>

template <class T, int Count>
struct map_pool_allocator
{
    using value_type = T;

    void* m_pool{nullptr};
    static constexpr std::size_t m_PoolSize{Count};

    size_t shift{0};

    map_pool_allocator () noexcept { }

    map_pool_allocator (const map_pool_allocator<T, Count>& a) noexcept
    {
        m_pool = a.m_pool;
    }

    T* allocate(std::size_t n)
    {
        if ((n * sizeof(T)) > (m_PoolSize * sizeof(T)) - shift)
        {
            throw std::bad_alloc();
        }

        if (!m_pool)
        {
            std::cout << "Try to allocate memory for m_pool\n";
            m_pool = ::operator new(m_PoolSize * sizeof(T));
            shift = 0;
        }

        auto result = reinterpret_cast<T*>(static_cast<char*>(m_pool) + shift);
        shift += n * sizeof(T);

        return result;
    }

    void deallocate (T* p, std::size_t n)
    {
        // free all memory at once
        if (m_pool)
        {
            std::cout << "Deallocate memory pool\n";
            ::operator delete(m_pool);
            m_pool = nullptr;
        }
    }

    template <class U>
    struct rebind
    {
        typedef map_pool_allocator<U, Count> other;
    };

    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type;
};

template <class T, class U, int Count>
constexpr bool operator== (const map_pool_allocator<T, Count>& a1, const map_pool_allocator<U, Count>& a2) noexcept
{
    return a1.pool == a2.pool;
}

template <class T, class U, int Count>
constexpr bool operator!= (const map_pool_allocator<T, Count>& a1, const map_pool_allocator<U, Count>& a2) noexcept
{
    return a1.pool != a2.pool;
}

namespace custom {
template <typename TKey, typename TValue, int Count>
using map = std::map<TKey, TValue, std::less<TKey>, map_pool_allocator<std::pair<const TKey, TValue>, Count>>;
} // namespace custom

int main()
{
    constexpr auto MaxCount{11};

    try
    {
        custom::map<int, int, MaxCount> mapWithCustomAllocator;
        for (int i{0}; i < MaxCount; ++i)
        {
            mapWithCustomAllocator.insert({i, i});
        }

        for (const auto& [key, value] : mapWithCustomAllocator)
        {
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }
    }
    catch (const std::bad_alloc&)
    {
        std::cerr << "Exception: trying to allocate memory for more than 10 elements\n";
    }
    catch (...)
    {
        std::cerr << "Unexpected exception catch\n";
    }

    return 0;
}
