//
// Created by Kevin Welton on 1/15/25.
//

#pragma once

#include "../stdafx.h"

constexpr size_t chunk_size = 12;
using chunk = std::array<uint8_t, chunk_size>;

//template <typename... chunk_pack>
//constexpr auto chunk_process(auto msg_it, size_t msg_len, chunk_pack... pack)
//{
//    chunk cur_chunk = {};
//
//    if (msg_len > chunk_size)
//    {
//        std::copy_n(msg_it, chunk_size, cur_chunk.begin());
//        std::advance(msg_it, chunk_size);
//        return chunk_process(msg_it, msg_len - chunk_size, pack..., cur_chunk);
//    }
//    else
//    {
//        std::copy_n(msg_it, msg_len, cur_chunk.begin());
//        return std::array<chunk, sizeof...(pack) + 1> {pack..., cur_chunk};
//    }
//}

//template <size_t N>
//constexpr auto chunk_process(const std::array<char, N> msg)
//{
//    chunk cur_chunk = {};
//
//    auto msg_it = msg.begin();
//
//    if (N > chunk_size)
//    {
//        std::copy_n(msg_it, chunk_size, cur_chunk.begin());
//        std::advance(msg_it, chunk_size);
//
//        return chunk_process(msg_it, N - chunk_size, cur_chunk);
//    }
//    else
//    {
//        std::copy_n(msg_it, N, cur_chunk.begin());
//        return std::array<chunk, 1> { cur_chunk };
//    }
//}

template <size_t N>
constexpr auto chunk_process(const std::array<char, N> msg)
{
    // need 1 byte for the end indicator and 8 bytes for the message size indicator
    constexpr size_t min_full_msg_size = (N + 1 + 8);

    constexpr size_t full_chunks = min_full_msg_size / chunk_size;
    constexpr size_t chunk_count = (min_full_msg_size % chunk_size > 0) ? full_chunks + 1 : full_chunks;

    std::array<chunk, chunk_count> chunks = { };

    // The arrays are contiguous, so just write all the bits.
    auto msg_it = msg.begin();
    std::copy_n(msg_it, N, chunks[0].begin());

    // Tack on the "1" to the end of the message
    auto dest_it = chunks[0].begin();
    std::advance(dest_it, N);
    *dest_it = 0x80;

    auto dest_reverse_it = chunks[chunk_count - 1].rbegin();
    std::advance(dest_reverse_it, sizeof(uint64_t) - 1);

    std::array<char, sizeof(N)> coda = std::bit_cast<std::array<char, sizeof(N)>>(N);
    std::copy_n(coda.begin(), coda.size(), chunks[chunk_count - 1].rbegin());

    return chunks;
}

template <size_t N>
constexpr auto chunkify(const char(&msg)[N])
{
    // Adjust for the null character
    std::array<char, N - 1> arr;
    std::copy_n(std::begin(msg), N - 1, arr.begin());

    return chunk_process(arr);
}
