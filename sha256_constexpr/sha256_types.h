//
// Created by Kevin Welton on 1/14/25.
//

#pragma once

#include "../stdafx.h"
#include "sha256_constants.h"

namespace sha256
{
    using hash_result = std::array<uint8_t, hash_result_size>;

    namespace internal
    {
        using chunk = std::array<uint8_t, chunk_length>;
    }
}