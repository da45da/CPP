// DLL1_Host.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "MathLib.h"
#include "DLL1_Host.h"
using namespace std;

bool b = false;

int main()
{
    string s;
    int i1 = getInteger(), i2 = getInteger();
    fibonacci_init(i1, i2);
    // Write out the sequence values until overflow.
    do 
    {
        std::cout << fibonacci_index() << ": " << fibonacci_current() << "\n";
    } while (fibonacci_next());

    std::cout << fibonacci_index() + 1 << " Fibonacci sequence values fit in an unsigned 64-bit integer (Given your starting numbers)." << "\n\n";

    std::cout << "Enter anything to close: ";
    cin >> s;
}

int getInteger()// Defines getInteger below
{
    int i1;
    std::string s1;
    bool b1 = false;

    while (not b1)
    {
        if (not b)
        std::cout << "Please enter an integer. \n";
        else
            std::cout << "Please enter another integer. \n";
        std::cin >> s1;

        try
        {
            i1 = std::stoi(s1);
            b1 = true;
        }
        catch (exception& err)
        {
            cout << "Conversion failure: " << err.what() << "\n\n";
        }
    }
    return i1;
}