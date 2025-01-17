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
        // Determine how many chunks we need
        //   - The minimum size of the message would be our message, plus what sha256 requires: A "1" bit tacked
        //     onto the end of the message and the final bits being an uint64_t in big-endian with the message
        //     size in bits. We will however many 512 bit chunks that will hold the entire message, including
        //     the stuff we have to append.
        constexpr size_t min_full_msg_size = (N + 1 + sizeof(uint64_t));
        constexpr size_t full_chunks = min_full_msg_size / chunk_length;
        constexpr size_t chunk_count = (min_full_msg_size % chunk_length > 0) ? full_chunks + 1 : full_chunks;

        // Allocate enough space in a plain byte array that will be equal in size to the number of chunks. This
        //   will make copying look a lot cleaner in code.
        std::array<uint8_t, chunk_count * chunk_length> chunks_raw = { };

        // The arrays are contiguous, so just write all the bits.
        //   Then tack on the "1" to the end of the message.
        auto msg_it = msg.begin();
        auto copy_result = std::ranges::copy_n(msg_it, N, chunks_raw.begin());
        *copy_result.out = 0x80;

        std::array<char, sizeof(uint64_t)> coda = std::bit_cast<std::array<char, sizeof(uint64_t)>>(N * bits_in_byte);
        std::copy_n(coda.begin(), coda.size(), chunks_raw.rbegin());

        // bit-cast from the raw buffer we were using for copying to the formatted structure. Same size and layout,
        //   so constexpr won't complain.
        return std::bit_cast<std::array<chunk, chunk_count>>(chunks_raw);
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