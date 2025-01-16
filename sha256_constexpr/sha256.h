//
// Created by Kevin Welton on 1/9/25.
//

#pragma once

#include "sha256_chunkify.h"

namespace sha256
{
    template<size_t N>
    constexpr hash_result sha256(const char(&msg)[N])
    {
        // We'll need enough chunks for:
        //   - The data
        //   - The extra "1" byte (big endian)
        //   - The uint64 message length (big endian, extra "1" byte does not count)
        constexpr size_t chunk_count = (N + 1 + sizeof(uint64_t)) / chunk_length;
        constexpr std::array<internal::chunk, chunk_count> chunks = chunkify<chunk_count>(std::to_array(msg));



        // Temp
        return hash_result();
    }
}