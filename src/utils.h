#pragma once

#include <ostream>
#include <tuple>

namespace utils {
    template<typename T, std::size_t... Is>
    std::ostream& printTupleImpl(std::ostream& os, const T& tuple, std::index_sequence<Is...>) {
        std::size_t idx = 0;
        auto printElement = [&idx, &os](const auto& x) {
            if (idx++ > 0) os << ".";
            os << x;
        };

        (printElement(std::get<Is>(tuple)), ...);

        return os;
    }

    template<typename T>
    int takeByte(T val, std::size_t byteNum) {
        return (val >> (8*byteNum)) & 0xff;
    }
}