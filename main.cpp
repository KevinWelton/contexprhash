#include "stdafx.h"

#include "sha256_constexpr/sha256_tests.h"

#include "proto/bitcast.h"

// BEGIN Use this section for testing diagnostic output with static assert
//template <sha256::hash_result val>
//struct c_array
//{
//    char data[val.size()] = {};
//
//    constexpr c_array()
//    {
//        std::ranges::copy_n(val.begin(), val.size(), std::begin(data));
//    }
//
//    constexpr const char* c_str() const
//    {
//        return data;
//    }
//};
//
//template <c_array hash_string>
//constexpr bool string_value = false;
//
//template <sha256::hash_result hash>
//void readable_static_assert()
//{
//    constexpr c_array<hash> hashstring;
//    static_assert(string_value<hashstring>);
//}
// END static assert test infrastructure

int main()
{
//    constexpr char test_short[] = "abcdefgh";
//
//    constexpr sha256::hash_result test_short_sha256 = sha256::sha256(test_short);
//
//    // Use one (or neither) of the following when testing depending on what you're currently debugging.
//
//    // Cause a compile failure that will print what was in the array
//    //readable_static_assert<test_short_sha256>();
//
//    // Use this one for testing with printf
//    std::array<char, sha256::hash_result_size + 1> stringified = {};
//    memcpy(stringified.data(), test_short_sha256.data(), sha256::hash_result_size);
//    printf("test_short_sha256\nValue=%s\nHash=%s\n\n", test_short, stringified.data());

// This is the old test for the chunkify prototype in the proto folder to make sure it works
    // constexpr char test_short[] = "abcdefghijklmnopq";
    // //constexpr char test_short[] = "a";
    // auto val = chunkify(test_short);
    // for (auto& chunk : val)
    // {
    //     for (auto val : chunk)
    //     {
    //         printf("%d ", val);
    //     }
    //
    //     printf("\n");
    // }

    // Test bitcast prototype
    //bitcast()

    sha256::tests::sha256_tests();

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.