//
// Created by Kevin Welton on 1/14/25.
//

#include "sha256_proto.h"

int main(int argc, char** argv)
{
    // =====================================================
    // Print some values from the consts to make sure they're correct

    printf("first and last byte of initial hash values: %d, %d\n", initial_hash[0][0], initial_hash[7][3]);
    printf("first and last byte of round constants: %d, %d\n", round_constant[0][0], round_constant[63][3]);

    // =====================================================

    constexpr char test_short[] = "abcdefgh";

    constexpr sha256_hash_result test_short_sha256 = sha256(test_short);

    // Use one (or neither) of the following when testing depending on what you're currently debugging.

    // Cause a compile failure that will print what was in the array
    //readable_static_assert<test_short_sha256>();

    // Use this one for testing with printf
    std::array<char, sha256_hash_result_size + 1> stringified = {};
    memcpy(stringified.data(), test_short_sha256.data(), sha256_hash_result_size);
    printf("test_short_sha256\nValue=%s\nHash=%s\n\n", test_short, stringified.data());

    return 0;
}