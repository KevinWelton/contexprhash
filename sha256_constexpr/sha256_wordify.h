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
        for (size_t i = 0; i < N; ++i)
        {
            auto chunk_it = chunks[i].begin();
            for (size_t j = 0; j < 16; ++j)
            {
                std::copy_n(chunk_it, chunk_word_length, words[i][j].begin());
                std::advance(chunk_it, chunk_word_length);
            }
        }

        for (size_t i = 0; i < N; ++i)
        {
            for (size_t j = 16; j < 64; ++j)
            {
                // TODO: Make sure we really need endianness stuff. I expect we do because of overflow.
                std::array<uint8_t, chunk_word_length> s0target_reversed = { };
                std::copy_n(words[i][j - 15].begin(), chunk_word_length, s0target_reversed.rbegin());
                uint32_t s0target_little_endian = std::bit_cast<uint32_t>(s0target_reversed);
                uint32_t s0a = std::rotr(s0target_little_endian, 7);
                uint32_t s0b = std::rotr(s0target_little_endian, 18);
                uint32_t s0c = std::rotr(s0target_little_endian, 3) & 0x1fffffff; // This is a shift operation
                uint32_t s0 = s0a ^ s0b ^ s0c;

                std::array<uint8_t, chunk_word_length> s1target_reversed = { };
                std::copy_n(words[i][j - 2].begin(), chunk_word_length, s1target_reversed.rbegin());
                uint32_t s1target_little_endian = std::bit_cast<uint32_t>(s1target_reversed);
                uint32_t s1a = std::rotr(s1target_little_endian, 17);
                uint32_t s1b = std::rotr(s1target_little_endian, 19);
                uint32_t s1c = std::rotr(s1target_little_endian, 10) & 0x003fffff; // This is a shift operation
                uint32_t s1 = s1a ^ s1b ^ s1c;

                // fix endianness for addition
                std::array<uint8_t, chunk_word_length> w0 = { };
                std::array<uint8_t, chunk_word_length> w1 = { };
                std::copy_n(words[i][j - 16].begin(),chunk_word_length, w0.rbegin());
                std::copy_n(words[i][j - 7].begin(), chunk_word_length, w1.rbegin());

                uint32_t sum = std::bit_cast<uint32_t>(w0) + s0 + std::bit_cast<uint32_t>(w1) + s1;
                std::array<uint8_t, chunk_word_length> sum_bigendian = std::bit_cast<std::array<uint8_t, chunk_word_length>>(sum);
                std::copy_n(sum_bigendian.rbegin(), sum_bigendian.size(), words[i][j].begin());
            }
        }

        return words;
    }
}
