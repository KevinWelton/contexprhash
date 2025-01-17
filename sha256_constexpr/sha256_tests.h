//
// Created by kevinwe on 1/16/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256.h"

namespace sha256::tests
{
    constexpr char empty_str[] = "";
    constexpr char short_str[] = "abcdefghijklmnopq";
    constexpr char fullchunk_with_room_for_coda[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabc";
    constexpr char almostfullchunk_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk";
    constexpr char fullchunk_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl";
    constexpr char fullchunk_and_a_half_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr";
    constexpr char twofullchunks_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl";

    // This is for printing a chunk
    // template <typename T>
    // void print_result(const char* test_name, size_t message_length, T chunks)
    // {
    //     printf("Test: %s\n", test_name);
    //     printf("Message length: %lu\n", message_length);
    //
    //     for (size_t i = 0; i < chunks.size(); ++i)
    //     {
    //         printf("Chunk %lu: ", i);
    //         for (auto& val : chunks[i])
    //         {
    //             printf("%d ", val);
    //         }
    //
    //         printf("\n");
    //     }
    //
    //     printf("\n");
    // }

    // This is for printing words
    // template <typename T>
    // void print_result(const char* test_name, size_t message_length, T chunk_words)
    // {
    //     printf("Test: %s\n", test_name);
    //     printf("Message length: %lu\n", message_length);
    //
    //     for (size_t i = 0; i < chunk_words.size(); ++i)
    //     {
    //         printf("Chunk %lu\n", i);
    //         for (size_t j = 0; j < words_per_chunk; ++j)
    //         {
    //             printf("Word %lu: ", j);
    //             for (auto& val : chunk_words[i][j])
    //             {
    //                 printf("%x ", val);
    //             }
    //
    //             printf("\n");
    //         }
    //
    //         printf("\n");
    //     }
    //
    //     printf("\n");
    // }

    void print_result(const char* test_name, size_t message_length, const hash_result result)
    {
        printf("Test: %s\n", test_name);
        printf("Message length: %lu\n", message_length);
        printf("SHA256: ");
        for (size_t i = 0; i < result.size(); ++i)
        {
            printf("%x", result[i]);
        }

        printf("\n");
    }

    void sha256_tests()
    {
        print_result("Empty string", strlen(empty_str), sha256::sha256(empty_str));
        print_result("Short string", strlen(short_str), sha256::sha256(short_str));
        print_result("Full chunk (including coda)", strlen(fullchunk_with_room_for_coda), sha256::sha256(fullchunk_with_room_for_coda));
        print_result("Full chunk - 1 (without coda)", strlen(almostfullchunk_str), sha256::sha256(almostfullchunk_str));
        print_result("Full chunk (without coda)", strlen(fullchunk_str), sha256::sha256(fullchunk_str));
        print_result("Full chunk + half chunk (without coda)", strlen(fullchunk_and_a_half_str), sha256::sha256(fullchunk_and_a_half_str));
        print_result("Two full chunks (without coda)", strlen(twofullchunks_str), sha256::sha256(twofullchunks_str));
    }
}