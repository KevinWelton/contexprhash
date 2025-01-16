//
// Created by kevinwe on 1/16/25.
//

#pragma once

#include "../stdafx.h"

void bitcast()
{
    std::array<uint8_t, 4> chars = { 0, 1, 0, 1 };

    uint32_t casted = std::bit_cast<uint32_t>(chars);
    printf("Casted value is %x\n", casted); // Will print 1000100 but should be laid out 00 01 00 01 in memory
    casted = std::rotr(casted, 1);
    printf("rshift 1 value is %x\n", casted); // Will print 800080 but should be laid out 80 00 80 00 in memory
}
