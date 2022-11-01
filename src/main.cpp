#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
#include <list>

#include "type_traits_extending.h"

template<typename T>
std::enable_if_t<std::is_integral<T>::value, void>
print_ip(T val) {
    (void)val;
    std::cout << "Integral type" << std::endl;
}

template<typename T>
std::enable_if_t<type_traits_extending::is_vector_or_list<T>::value, void>
print_ip(T val) {
    (void)val;
    std::cout << "Array type" << std::endl;
}

int main (int, char **) {
    print_ip( int8_t{-1} ); // 255
    print_ip( int16_t{0} ); // 0.0
    print_ip( int32_t{2130706433} ); // 127.0.0.1
    print_ip( int64_t{8875824491850138409} );// 123.45.67.89.101.112.131.41

    std::cout << type_traits_extending::is_vector_or_list<int8_t>::value << std::endl;
    std::cout << type_traits_extending::is_vector_or_list<std::vector<int>>::value << std::endl;
    std::cout << type_traits_extending::is_vector_or_list<std::vector<double>>::value << std::endl;
    std::cout << type_traits_extending::is_vector_or_list<std::vector<char*>>::value << std::endl;
    std::cout << type_traits_extending::is_vector_or_list<std::list<std::string>>::value << std::endl;
    std::cout << type_traits_extending::is_vector_or_list<std::string>::value << std::endl;

    std::cout << std::endl;


//        print_ip( std::string{"Hello, World!"} ); // Hello, World!
    print_ip( std::vector<int>{100, 200, 300, 400} ); // 100.200.300.400
    print_ip( std::list<short>{400, 300, 200, 100} ); // 400.300.200.100
//    print_ip( std::make_tuple(123, 456, 789, 0) ); // 123.456.789.0

    return 0;
}
