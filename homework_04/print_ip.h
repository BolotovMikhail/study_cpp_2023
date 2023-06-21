#include <iostream>

template<typename T>
auto print_ip(T val) -> typename std::enable_if_t<std::is_same_v<T, std::string>>
{
    std::cout << val << std::endl;
}

template<typename T>
auto print_ip(T ip) -> typename std::enable_if_t<std::is_integral_v<T>>
{
    uint8_t* bytesPtr = reinterpret_cast<uint8_t*>(&ip);
    for (int i{sizeof(ip) - 1}; i >= 0; --i)
    {
        std::cout << static_cast<int>(bytesPtr[i]);
        if (i > 0)
        {
            std::cout << ".";
        }
    }
    std::cout << "\n";
}

template<typename T>
auto print_ip(T container) -> typename std::enable_if_t<!std::is_same_v<typename T::value_type, char>>
{
    std::string separator = "";
    for (const auto& val : container)
    {
        std::cout << separator << val;
        separator = ".";
    }
    std::cout << "\n";
}

template<class TupleType, size_t... I>
void print_tuple(const TupleType& Ip, std::index_sequence<I...>)
{
    (..., (std::cout << (I == 0 ? "" : ".") << std::get<I>(Ip) ));
}

template<class... T>
void print_tuple(const std::tuple<T...>& Ip)
{
    print_tuple(Ip, std::make_index_sequence<sizeof...(T)>());
    std::cout << "\n";
}

template<typename T>
auto print_ip(T container) -> typename std::enable_if_t<std::is_same_v<typename std::tuple_size<T>::value_type, std::size_t>>
{
    print_tuple(container);
}
