//
// Created by Kevin Welton on 1/14/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_types.h"

namespace sha256::internal
{
    template <size_t N>
    constexpr auto chunk_process(const std::array<char, N> msg)
    {
        // need 1 byte for the end indicator and 8 bytes for the message size indicator
        constexpr size_t min_full_msg_size = (N + 1 + 8);

        constexpr size_t full_chunks = min_full_msg_size / sha256::chunk_length;
        constexpr size_t chunk_count = (min_full_msg_size % sha256::chunk_length > 0) ? full_chunks + 1 : full_chunks;

        std::array<chunk, chunk_count> chunks = { };

        // The arrays are contiguous, so just write all the bits.
        size_t bytes_left = N;
        auto chunk_it = chunks.begin();
        auto msg_it = msg.begin();

        while (bytes_left >= chunk_length)
        {
            std::copy_n(msg_it, chunk_length, (*chunk_it).begin());
            std::advance(msg_it, chunk_length);
            std::advance(chunk_it, 1);

            bytes_left -= chunk_length;
        }

        auto chunk_data_it = (*chunk_it).begin();
        if (bytes_left)
        {
            std::copy_n(msg_it, bytes_left, chunk_data_it);
            std::advance(chunk_data_it, bytes_left);
        }

        if (chunk_data_it == (*chunk_it).end())
        {
            std::advance(chunk_it, 1);
            chunk_data_it = (*chunk_it).begin();
        }

        // Tack on the "1" to the end of the message
        *chunk_data_it = 0x80;

        // Add the length onto the very end of the chunks
        auto dest_reverse_it = chunks[chunk_count - 1].rbegin();
        std::advance(dest_reverse_it, sizeof(uint64_t) - 1);

        std::array<char, sizeof(N)> coda = std::bit_cast<std::array<char, sizeof(N)>>(N * bits_in_byte);
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
}