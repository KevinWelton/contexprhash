#include "stdafx.h"

#include "sha256_constexpr/sha256_tests.h"

#include "proto/bitcast.h"

int main()
{
    // Unit tests
    sha256::tests::sha256_tests();

    return 0;
}
