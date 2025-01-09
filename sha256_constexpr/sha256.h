//
// Created by Kevin Welton on 1/9/25.
//

#pragma once

#include <string>

// temp
constexpr std::string placeholder(const std::string msg)
{
    return msg + "12345";
}

constexpr std::string sha256(const std::string msg)
{
    return placeholder(msg);
}