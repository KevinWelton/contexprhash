cmake_minimum_required(VERSION 3.30)
project(constexprhash)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-type -fdiagnostics-show-template-tree")
#set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(constexprhash main.cpp
        sha256_constexpr/sha256.h
        sha256_constexpr/sha256_constants.h
        sha256_constexpr/sha256_chunkify.h
        proto/sha256_proto.h
        sha256_constexpr/sha256_types.h
        stdafx.h
        sha256_constexpr/sha256_tests.h
        sha256_constexpr/sha256_wordify.h
)
