//
// Created by kevinwe on 1/16/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256.h"

namespace sha256::tests
{
    void print_result(const char* test_name, const sha256_hash result, const char* expected)
    {
        printf("Test    : %s\n", test_name);
        printf("SHA256  : %s\n", result.data());
        printf("Expected: %s\n\n", expected);
    }

    void sha256_tests()
    {
        constexpr char empty_str[] = "";
        constexpr char short_str[] = "abcdefghijklmnopq";
        constexpr char fullchunk_with_room_for_coda[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabc";
        constexpr char almostfullchunk_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijk";
        constexpr char fullchunk_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl";
        constexpr char fullchunk_and_a_half_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqr";
        constexpr char twofullchunks_str[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl";
        constexpr char long_str[] = "Flibbertygibbet snickerfuzzled blorptastic wibberly-wobberly goobledygook. Whimsiflex sploofy mizzle-wizzle tiddlewhackery, hoopledoo ziggity zaggity bopplekins. Squiffledorf flumplewump zibble-wibble, fluffernutter snorfigan gloobernoodle. Floofalooze crinklefloss jubberwobble plimpity-squish bamboozle. Twiddlytwop zeeblefloop gloopity boingle boomp, wobbledy woozle zopfred snarfblatt!";

        // Use this two-line format to make sure these are evaluated as constexpr
        constexpr sha256_hash empty_str_result = sha256(empty_str);
        print_result("Empty string", empty_str_result, "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");

        constexpr sha256_hash short_str_result = sha256(short_str);
        print_result("Short string", short_str_result, "918a954ac4dfb54ac39f068d9868227f69ab39bc362e2c9b0083bf6a109d6ad7");

        constexpr sha256_hash fullchunk_with_room_for_coda_result = sha256(fullchunk_with_room_for_coda);
        print_result("Full chunk (including coda)", fullchunk_with_room_for_coda_result, "595615dbe4f0f407ae397d08b4c2cb870cb9b0e11937416f950c5160acf9c005");

        constexpr sha256_hash almostfullchunk_str_result = sha256(almostfullchunk_str);
        print_result("Full chunk - 1 (without coda)", almostfullchunk_str_result, "5ca3e1ef5207490eac01a795e5cc94d59582a5118bf9534665c8668d87aa647c");

        constexpr sha256_hash fullchunk_str_result = sha256(fullchunk_str);
        print_result("Full chunk (without coda)", fullchunk_str_result, "2fcd5a0d60e4c941381fcc4e00a4bf8be422c3ddfafb93c809e8d1e2bfffae8e");

        constexpr sha256_hash fullchunk_and_a_half_str_result = sha256(fullchunk_and_a_half_str);
        print_result("Full chunk + half chunk (without coda)", fullchunk_and_a_half_str_result, "b43a6f5b8ea065c9a16792115fd1074296a726182cc199532196e4675f45caae");

        constexpr sha256_hash twofullchunks_str_result = sha256(twofullchunks_str);
        print_result("Two full chunks (without coda)", twofullchunks_str_result, "f8a3f226fc4210e90d130c7f41f2be66455385d2920ada7815f8f795d944905f");

        constexpr sha256_hash long_str_result = sha256(long_str);
        print_result("Long string", long_str_result, "dd58f9df173204837305b3a7bbc56097318682fbc3efe10e91340873ca71783d");
    }
}