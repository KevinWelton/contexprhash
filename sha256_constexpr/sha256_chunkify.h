//
// Created by Kevin Welton on 1/14/25.
//

#pragma once

#include "sha256_types.h"

namespace sha256
{
    namespace internal
    {
        template <size_t N>
        constexpr auto chunkify_processing(std::array<uint8_t, N>, size_t chunk)
        {

        }

        template<size_t N, size_t M>
        constexpr auto chunkify(std::array<uint8_t, M> msg)
        {
            return chunkify_processing(msg, 0);
        }
    }
}