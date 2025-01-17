//
// Created by Kevin Welton on 1/9/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_chunkify.h"
#include "sha256_wordify.h"
#include "sha256_compression.h"

namespace sha256
{
    template<size_t N>
    constexpr auto sha256(const char(&msg)[N])
    {
        return sha256::internal::compress(
            sha256::internal::wordify(
                sha256::internal::chunkify(msg)));
    }
}