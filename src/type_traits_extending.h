#pragma once

#include <type_traits>
#include <vector>
#include <list>

struct type_traits_extending {
private:

    template<typename T1, typename T2>
    struct _or : std::conditional<T1::value, T1, T2>::type {};

    struct _do_is_vector_or_list_impl {
        template<
                typename T,
                typename ItemType = typename T::value_type,
                typename AllocatorType = typename T::allocator_type,
                typename = std::enable_if_t<
                        _or<
                                typename std::is_same<T, std::vector<ItemType, AllocatorType>>::type,
                                typename std::is_same<T, std::list<ItemType, AllocatorType>>::type
                        >::value,
                        void>
        >
        static std::true_type _test(int);

        template<typename>
        static std::false_type _test(...);
    };

    template<typename T>
    struct _is_vector_or_list_impl : _do_is_vector_or_list_impl {
        typedef decltype(_test<T>(0)) type;
    };

public:
    template<typename T>
    struct is_vector_or_list : _is_vector_or_list_impl<T>::type {};
};
