#pragma once
#include <string>

struct Cars// Declares a public data structre designated Cars
{
    std::string brand;
    std::string model;
    int year;
    int MSRP;
    std::byte tirenum;
    std::byte doornum;
    std::byte seats;
    std::byte hp;
    // Declares several variables within the structre
};// Ends the scope of Cars

void getarr();// Declares the function getarr
void getvec();// Declares the function getvec