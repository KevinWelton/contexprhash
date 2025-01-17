//
// Created by kevinwe on 1/16/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_types.h"

namespace sha256::internal
{
    constexpr auto stringify(const hash_result result)
    {
        sha256_hash str = { };
        auto str_it = std::begin(str);

        constexpr auto bits_to_char = [] (const uint8_t bits) -> char {
            return (bits < 10) ? bits + '0' : (bits - 10) + 'a';
        };

        for (const uint8_t result_byte : result)
        {
            *str_it = bits_to_char(result_byte >> 4);
            str_it++;
            *str_it = bits_to_char(result_byte & 0x0f);
            str_it++;
        }

        return str;
    }

    template <size_t N>
    constexpr auto compress(const std::array<std::array<std::array<uint8_t, chunk_word_length>, words_per_chunk>, N> chunks)
    {
        // Initialize hash values
        std::array<uint32_t, 8> hash_vals = { };
        std::copy_n(initial_hash.begin(), hash_vals.size(), hash_vals.begin());

        for (size_t i = 0; i < N; ++i)
        {
            std::array<uint32_t, 8> chunk_hash_vals = { };
            std::copy_n(hash_vals.begin(), chunk_hash_vals.size(), chunk_hash_vals.begin());

            for (size_t j = 0; j < 64; ++j)
            {
                std::array<uint8_t, chunk_word_length> word_reversed = { };
                std::copy_n(chunks[i][j].begin(), chunk_word_length, word_reversed.rbegin());
                uint32_t word_little_endian = std::bit_cast<uint32_t>(word_reversed);

                uint32_t summation1 = std::rotr(chunk_hash_vals[4], 6) ^ std::rotr(chunk_hash_vals[4], 11) ^ std::rotr(chunk_hash_vals[4], 25);
                uint32_t choice = (chunk_hash_vals[4] & chunk_hash_vals[5]) ^ ((~chunk_hash_vals[4]) & chunk_hash_vals[6]);
                uint32_t temp1 = chunk_hash_vals[7] + summation1 + choice + round_constant[j] + word_little_endian;

                uint32_t summation0 = std::rotr(chunk_hash_vals[0], 2) ^ std::rotr(chunk_hash_vals[0], 13) ^ std::rotr(chunk_hash_vals[0], 22);
                uint32_t majority = (chunk_hash_vals[0] & chunk_hash_vals[1]) ^ (chunk_hash_vals[0] & chunk_hash_vals[2]) ^ (chunk_hash_vals[1] & chunk_hash_vals[2]);
                uint32_t temp2 = summation0 + majority;

                chunk_hash_vals[7] = chunk_hash_vals[6];
                chunk_hash_vals[6] = chunk_hash_vals[5];
                chunk_hash_vals[5] = chunk_hash_vals[4];
                chunk_hash_vals[4] = chunk_hash_vals[3] + temp1;
                chunk_hash_vals[3] = chunk_hash_vals[2];
                chunk_hash_vals[2] = chunk_hash_vals[1];
                chunk_hash_vals[1] = chunk_hash_vals[0];
                chunk_hash_vals[0] = temp1 + temp2;
            }

            hash_vals[0] += chunk_hash_vals[0];
            hash_vals[1] += chunk_hash_vals[1];
            hash_vals[2] += chunk_hash_vals[2];
            hash_vals[3] += chunk_hash_vals[3];
            hash_vals[4] += chunk_hash_vals[4];
            hash_vals[5] += chunk_hash_vals[5];
            hash_vals[6] += chunk_hash_vals[6];
            hash_vals[7] += chunk_hash_vals[7];
        }

        hash_result result = { };
        auto result_it = result.begin();

        for (size_t i = 0; i < 8; ++i)
        {
            std::array<uint8_t, chunk_word_length> hash_val = std::bit_cast<std::array<uint8_t, chunk_word_length>>(hash_vals[i]);
            std::copy_n(hash_val.rbegin(), chunk_word_length, result_it);
            std::advance(result_it, chunk_word_length);
        }

        return stringify(result);
    }
}
