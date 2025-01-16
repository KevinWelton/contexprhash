//
// Created by kevinwe on 1/16/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_types.h"

namespace sha256::internal
{
    template <size_t N>
    constexpr auto wordify(const std::array<chunk, N> chunks)
    {
        // Each chunk gets split into 64 32-bit words. Copy the chunk into the first 16 words.
        std::array<std::array<std::array<uint8_t, chunk_word_length>, words_per_chunk>, N> words = { };
        for (size_t i = 0; i < chunks.size(); ++i)
        {
            std::copy_n(chunks[i].begin(), chunk_length, words[i][0].begin());
        }

        return words;
    }
}
