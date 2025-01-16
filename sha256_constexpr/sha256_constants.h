//
// Created by Kevin Welton on 1/14/25.
//

#pragma once

#include <array>

namespace sha256
{
    // In bytes
    constexpr size_t chunk_word_length = 4;
    constexpr size_t chunk_length = 512 / chunk_word_length;
    constexpr size_t hash_result_size =  256 / chunk_word_length;

    constexpr std::array<std::array<uint8_t, 4>, 8> initial_hash = {{
        {0x6a, 0x09, 0xe6, 0x67},
        {0xbb, 0x67, 0xae, 0x85},
        {0x3c, 0x6e, 0xf3, 0x72},
        {0xa5, 0x4f, 0xf5, 0x3a},
        {0x51, 0x0e, 0x52, 0x7f},
        {0x9b, 0x05, 0x68, 0x8c},
        {0x1f, 0x83, 0xd9, 0xab},
        {0x5b, 0xe0, 0xcd, 0x19}}};

    constexpr std::array<std::array<uint8_t, 4>, 64> round_constant = {{
        {0x42, 0x8a, 0x2f, 0x98},
        {0x71, 0x37, 0x44, 0x91},
        {0xb5, 0xc0, 0xfb, 0xcf},
        {0xe9, 0xb5, 0xdb, 0xa5},
        {0x39, 0x56, 0xc2, 0x5b},
        {0x59, 0xf1, 0x11, 0xf1},
        {0x92, 0x3f, 0x82, 0xa4},
        {0xab, 0x1c, 0x5e, 0xd5},
        {0xd8, 0x07, 0xaa, 0x98},
        {0x12, 0x83, 0x5b, 0x01},
        {0x24, 0x31, 0x85, 0xbe},
        {0x55, 0x0c, 0x7d, 0xc3},
        {0x72, 0xbe, 0x5d, 0x74},
        {0x80, 0xde, 0xb1, 0xfe},
        {0x9b, 0xdc, 0x06, 0xa7},
        {0xc1, 0x9b, 0xf1, 0x74},
        {0xe4, 0x9b, 0x69, 0xc1},
        {0xef, 0xbe, 0x47, 0x86},
        {0x0f, 0xc1, 0x9d, 0xc6},
        {0x24, 0x0c, 0xa1, 0xcc},
        {0x2d, 0xe9, 0x2c, 0x6f},
        {0x4a, 0x74, 0x84, 0xaa},
        {0x5c, 0xb0, 0xa9, 0xdc},
        {0x76, 0xf9, 0x88, 0xda},
        {0x98, 0x3e, 0x51, 0x52},
        {0xa8, 0x31, 0xc6, 0x6d},
        {0xb0, 0x03, 0x27, 0xc8},
        {0xbf, 0x59, 0x7f, 0xc7},
        {0xc6, 0xe0, 0x0b, 0xf3},
        {0xd5, 0xa7, 0x91, 0x47},
        {0x06, 0xca, 0x63, 0x51},
        {0x14, 0x29, 0x29, 0x67},
        {0x27, 0xb7, 0x0a, 0x85},
        {0x2e, 0x1b, 0x21, 0x38},
        {0x4d, 0x2c, 0x6d, 0xfc},
        {0x53, 0x38, 0x0d, 0x13},
        {0x65, 0x0a, 0x73, 0x54},
        {0x76, 0x6a, 0x0a, 0xbb},
        {0x81, 0xc2, 0xc9, 0x2e},
        {0x92, 0x72, 0x2c, 0x85},
        {0xa2, 0xbf, 0xe8, 0xa1},
        {0xa8, 0x1a, 0x66, 0x4b},
        {0xc2, 0x4b, 0x8b, 0x70},
        {0xc7, 0x6c, 0x51, 0xa3},
        {0xd1, 0x92, 0xe8, 0x19},
        {0xd6, 0x99, 0x06, 0x24},
        {0xf4, 0x0e, 0x35, 0x85},
        {0x10, 0x6a, 0xa0, 0x70},
        {0x19, 0xa4, 0xc1, 0x16},
        {0x1e, 0x37, 0x6c, 0x08},
        {0x27, 0x48, 0x77, 0x4c},
        {0x34, 0xb0, 0xbc, 0xb5},
        {0x39, 0x1c, 0x0c, 0xb3},
        {0x4e, 0xd8, 0xaa, 0x4a},
        {0x5b, 0x9c, 0xca, 0x4f},
        {0x68, 0x2e, 0x6f, 0xf3},
        {0x74, 0x8f, 0x82, 0xee},
        {0x78, 0xa5, 0x63, 0x6f},
        {0x84, 0xc8, 0x78, 0x14},
        {0x8c, 0xc7, 0x02, 0x08},
        {0x90, 0xbe, 0xff, 0xfa},
        {0xa4, 0x50, 0x6c, 0xeb},
        {0xbe, 0xf9, 0xa3, 0xf7},
        {0xc6, 0x71, 0x78, 0xf2}}};
}