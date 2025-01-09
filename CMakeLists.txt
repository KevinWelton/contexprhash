cmake_minimum_required(VERSION 3.30)
project(constexprhash)

set(CMAKE_CXX_STANDARD 20)

add_executable(constexprhash main.cpp
        sha256_constexpr/sha256.h
        sha256_constexpr/sha256-msgblock-phase1.h
        sha256_constexpr/sha256-algorithm.h)
