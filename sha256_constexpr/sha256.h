//
// Created by Kevin Welton on 1/9/25.
//

#pragma once

#include "sha256_constants.h"

static constexpr size_t sha256_hash_result_size = 256;
using sha256_hash_result = std::array<char, sha256_hash_result_size>;

template <size_t N, size_t M, size_t... I1, size_t... I2>
constexpr sha256_hash_result array_concat_impl(
        const std::array<char, N> first,
        const std::array<char, M> second,
        std::index_sequence<I1...>,
        std::index_sequence<I2...>)
{
    return { first[I1]..., second[I2]... };
}

template <size_t N, size_t M>
constexpr sha256_hash_result array_concat(const std::array<char, N> first, const std::array<char, M> second)
{
    return array_concat_impl(first, second, std::make_index_sequence<N - 1> {}, std::make_index_sequence<M - 1> {});
}


//temp
template <size_t N>
constexpr sha256_hash_result placeholder(const std::array<char, N> msg)
{
    constexpr char append_str[] = "12345";
    return array_concat(msg, std::to_array(append_str));
}

template <size_t N>
constexpr sha256_hash_result sha256(const char(&msg)[N])
{
    return placeholder(std::to_array(msg));
}