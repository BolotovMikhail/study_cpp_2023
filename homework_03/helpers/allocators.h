#ifndef HELPERS_ALLOCATORS_H
#define HELPERS_ALLOCATORS_H

#include <iostream>
#include <map>

template <class T, int Count>
struct map_pool_allocator
{
    using value_type = T;
    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type;

    map_pool_allocator () noexcept { }

    map_pool_allocator (const map_pool_allocator<T, Count>& other)
    {
        if (other.get_capacity() > get_capacity())
        {
            throw std::bad_alloc();
        }
        m_pool = other.m_pool;
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
        if (m_PoolSize == 1)
        {
            std::cout << "Deallocate memory pool\n";
            ::operator delete(m_pool);
            m_pool = nullptr;
        }
        m_PoolSize -= n;
    }

    template <class U>
    struct rebind
    {
        typedef map_pool_allocator<U, Count> other;
    };

    std::size_t get_capacity()
    {
        return m_PoolSize;
    }

private:
    void* m_pool{nullptr};
    std::size_t m_PoolSize{Count};
    std::size_t shift{0};
};

template <class T, int Count>
constexpr bool operator== (const map_pool_allocator<T, Count>& a1,
    const map_pool_allocator<T, Count>& a2) noexcept
{
    return a1.pool == a2.pool;
}

template <class T, int Count>
constexpr bool operator!= (const map_pool_allocator<T, Count>& a1,
    const map_pool_allocator<T, Count>& a2) noexcept
{
    return a1.pool != a2.pool;
}

namespace custom {
template <typename TKey, typename TValue, int Count>
using map = std::map<TKey, TValue, std::less<TKey>,
    map_pool_allocator<std::pair<const TKey, TValue>, Count>>;
} // namespace custom

template <class T, int Count>
struct custom_container_pool_allocator
{
    using value_type = T;
    using propagate_on_container_copy_assignment = std::true_type;
    using propagate_on_container_move_assignment = std::true_type;
    using propagate_on_container_swap = std::true_type;

    custom_container_pool_allocator () noexcept { }

    custom_container_pool_allocator (const custom_container_pool_allocator<T, Count>& other)
    {
        if (other.get_capacity() > get_capacity())
        {
            throw std::bad_alloc();
        }
        m_pool = other.m_pool;
    }

    T* allocate(std::size_t n)
    {
        if ((n * sizeof(T)) > (m_PoolSize * sizeof(T)))
        {
            throw std::bad_alloc();
        }

        if (!m_pool)
        {
            std::cout << "Try to allocate memory for m_pool\n";
            m_pool = ::operator new(m_PoolSize * sizeof(T));
        }

        return reinterpret_cast<T*>(m_pool);
    }

    void deallocate (T* p, std::size_t n)
    {
        // free all memory at once
        if (p)
        {
            std::cout << "Deallocate memory pool\n";
            ::operator delete(p);
            p = nullptr;
        }
    }

    template <class U>
    struct rebind
    {
        typedef custom_container_pool_allocator<U, Count> other;
    };

    std::size_t get_capacity()
    {
        return m_PoolSize;
    }

private:
    void* m_pool{nullptr};
    static constexpr std::size_t m_PoolSize{Count};
};

template <class T, int Count>
constexpr bool operator== (const custom_container_pool_allocator<T, Count>& a1,
    const custom_container_pool_allocator<T, Count>& a2) noexcept
{
    return a1.pool == a2.pool;
}

template <class T, int Count>
constexpr bool operator!= (const custom_container_pool_allocator<T, Count>& a1,
    const custom_container_pool_allocator<T, Count>& a2) noexcept
{
    return a1.pool != a2.pool;
}

#endif // HELPERS_ALLOCATORS_H
