#pragma once

#include <iostream>
#include <random>
#include <Windows.h>
#include <string>
#include <stddef.h>
class rando
{
public:
    int random(int min = 0, int max = UINT32_MAX);
    void rndbarr(byte* barr, size_t size);

    rando();
    ~rando();

private:
    std::random_device rd;// Declares a random agent
};