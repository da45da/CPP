#pragma once
#include <iostream>
#include <random>
#include <Windows.h>
#include <string>
#include <chrono>
#include <stddef.h>
#include <cstdint>
using namespace std;
typedef unsigned char BYTE;
class rando
{
public:
    void rndbarr(BYTE* barr, size_t size);
    rando();
    ~rando();

private:
    std::random_device rd;// Declares a random agent
};

class xorand
{
public:
    void doand();
    void door();
    void doxor();

    void doand32();
    void door32();
    void doxor32();

    xorand();
    ~xorand();

    int i2 = 10000000;
    BYTE* ba1 = new BYTE[i2];
    BYTE* ba2 = new BYTE[i2];
    uint32_t * ba14 = (uint32_t*)ba1, * ba24 = (uint32_t*)ba2, i24 = i2 / 4;
};