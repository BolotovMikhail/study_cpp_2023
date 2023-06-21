#include <iostream>
#include <type_traits>
#include <tuple>

/*
 * print_ip for - std::string input parameter
 *
 * Prints the input string as is
 *
 * @param val
 *   input value of type std::string
 *
 * @return
 *   return value not explicitly used
*/
template<typename T>
auto print_ip(T val) -> typename std::enable_if_t<std::is_same_v<T, std::string>>
{
    std::cout << val << std::endl;
}

/*
 * print_ip - for integer input parameter
 *
 * Prints unsigned byte-by-byte, high byte first,
 * with `.` (dot character) as delimiter.
 * All bytes of the number are output.
 *
 * @param ip
 *   input value of integer type
 *
 * @return
 *   return value not explicitly used
*/
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

/*
 * print_ip - for input container type with integer values
 *
 * Prints the values of the input container (std::vector or std::list)
 * to standard output with `.` (dot character) as delimiter.
 *
 * @param container
 *   std::vector or std::list with integer values
 *
 * @return
 *   return value not explicitly used
*/
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

/*
 * print_tuple - prints all values that std::tuple contains
 *
 * @param TupleType
 *   type std::tuple with any values
 * @param size_t... I
 *   tuple index sequence
 *
 * @return void
*/
template<class TupleType, size_t... I>
void print_tuple(const TupleType& Ip, std::index_sequence<I...>)
{
    (..., (std::cout << (I == 0 ? "" : ".") << std::get<I>(Ip) ));
}

/*
 * print_tuple - prints all values that std::tuple contains
 *
 * Calls a more detailed specialization of the print_tuple function
 * 
 * @param T
 *   type std::tuple with any values
 *
 * @return void
*/
template<class... T>
void print_tuple(const std::tuple<T...>& Ip)
{
    print_tuple(Ip, std::make_index_sequence<sizeof...(T)>());
    std::cout << "\n";
}

/*
 * print_ip - for input std::tuple type
 *
 * Calls the print tuple function, which prints the entire tuple
 * 
 * @param T
 *   type std::tuple with any values
 *
 * @return void
*/
template<typename T>
auto print_ip(T container) -> typename std::enable_if_t<std::is_same_v<typename std::tuple_size<T>::value_type, std::size_t>>
{
    print_tuple(container);
}
