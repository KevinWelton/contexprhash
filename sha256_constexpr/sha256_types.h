//
// Created by Kevin Welton on 1/14/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_constants.h"

namespace sha256
{
    using sha256_hash = std::array<char, internal::hash_result_string_length + 1>;

    namespace internal
    {
        using chunk = std::array<uint8_t, chunk_length>;
        using chunk_words = std::array<std::array<uint8_t, sizeof(uint32_t)>, words_per_chunk>;
        using compression_vars = std::array<uint32_t, compression_var_count>;
        using hash_result = std::array<uint8_t, hash_result_size>;
    }
}