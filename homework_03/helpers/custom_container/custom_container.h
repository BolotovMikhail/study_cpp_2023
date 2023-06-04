#ifndef HELPERS_CUSTOM_CONTAINER_H
#define HELPERS_CUSTOM_CONTAINER_H

#include <iostream>

template<class Allocator = std::allocator<int>>
class SimpleCustomContainer
{
public:
    SimpleCustomContainer() = delete;
    explicit SimpleCustomContainer(const int N) noexcept :
        m_capacity{static_cast<size_t>(N + 1)}
    {
        m_data = alloc.allocate(m_capacity);
    }

    explicit SimpleCustomContainer(const std::initializer_list<int> init_list) noexcept :
        m_capacity{static_cast<size_t>(init_list.size() + 1)}
    {
        m_data = alloc.allocate(m_capacity);
        size_t i{0};
        for (const auto& value : init_list)
        {
            m_data[++m_size] = value;
        }
    }

    ~SimpleCustomContainer()
    {
        std::cout << "~SimpleCustomContainer() -> deallocate " << m_capacity << "\n";
        alloc.deallocate(m_data, m_capacity);
    }

    void PushBack(const int value)
    {
        if (m_size == m_capacity)
        {
            std::cout << "PushBack " << value << " -> allocate\n";
            m_capacity = static_cast<size_t>(m_capacity + 1);
            int* sameData = alloc.allocate(m_capacity); // it's m_data
            //std::copy(m_data, m_data + m_size * sizeof(int), newData);
            // NOT IMPLEMENTED
            // alloc.deallocate(newData, m_capacity);
        }
        SetData(m_size, value);
    }

    void SetData(const int index, const int value)
    {
        m_data[index] = value;
        ++m_size;
    }

    int GetData(const int index) const
    {
        return m_data[index];
    }

    size_t GetSize() const noexcept
    {
        return m_size;
    }

    size_t GetCapacity() const noexcept
    {
        return m_capacity;
    }

    void PrintData(const size_t N) const
    {
        std::cout << "[Size: " << m_size << " Capacity: " << m_capacity << "] Values: ";
        for (size_t i{0}; i < N; ++i)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << "\n";
    }

    void PrintData() const
    {
        std::cout << "[Size: " << m_size << " Capacity: " << m_capacity << "] Values: ";
        for (size_t i{0}; i < m_size; ++i)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << "\n";
    }

    SimpleCustomContainer(const SimpleCustomContainer&) = delete;
    SimpleCustomContainer(SimpleCustomContainer&&) = delete;
    SimpleCustomContainer& operator=(const SimpleCustomContainer&) = delete;
    SimpleCustomContainer& operator=(SimpleCustomContainer&&) = delete;

private:
    Allocator alloc;
    size_t m_size{0};
    size_t m_capacity{0};
    int* m_data{nullptr};
};

#endif // HELPERS_CUSTOM_CONTAINER_H
