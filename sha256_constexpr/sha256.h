//
// Created by Kevin Welton on 1/9/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_chunkify.h"

namespace sha256
{
    template<size_t N>
    constexpr auto sha256(const char(&msg)[N])
    {
        auto chunks = sha256::internal::chunkify(msg);



        // Temp
        return chunks;
    }
}