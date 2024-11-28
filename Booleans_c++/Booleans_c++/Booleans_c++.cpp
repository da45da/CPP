/*  Damian Attia-Barillas
    Did this program compile? Yes
    Did this program run as expected? Yes
    Mark that you think you deserve. 99%

    1) Learned how much faster a 4-byte system is compared to checking each one individually

    I believe that 99% is reasonable because all of the new functions therein work as intended, and all the mean times are recorded below

    Note: Average times to complete each task:

    Generate:   19.72ms
    && operand: 39.76ms
    &&(x86):    11.22ms
    &&(x64):    15.19ms
    || operand: 51.41ms
    ||(x86):    12.33ms
    ||(x64):    13.22ms
    ^^ operand: 33.33ms
    ^^(x86):    19.67ms
    ^^(x64):    25.01ms
    Total time: 270.75ms
    */

#include "Booleans_c++.h"

int main()
{
    string s;

    auto start = std::chrono::high_resolution_clock::now();
    auto finish = std::chrono::high_resolution_clock::now();
    auto begin1 = std::chrono::high_resolution_clock::now();
    auto begin2 = std::chrono::high_resolution_clock::now();
    auto begin232 = std::chrono::high_resolution_clock::now();
    auto begin3 = std::chrono::high_resolution_clock::now();
    auto begin332 = std::chrono::high_resolution_clock::now();
    auto begin4 = std::chrono::high_resolution_clock::now();
    auto begin432 = std::chrono::high_resolution_clock::now();
    auto end1 = std::chrono::high_resolution_clock::now();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto end232 = std::chrono::high_resolution_clock::now();
    auto end3 = std::chrono::high_resolution_clock::now();
    auto end332 = std::chrono::high_resolution_clock::now();
    auto end4 = std::chrono::high_resolution_clock::now();
    auto end432 = std::chrono::high_resolution_clock::now();
    // Declares the timers that will be used during the program

    start = std::chrono::high_resolution_clock::now();// Stops start's timer

    rando* ran = new rando();
    xorand* xnd = new xorand();
   
    begin1 = std::chrono::high_resolution_clock::now();
    ran->rndbarr(xnd->ba1, xnd->i2);// Generates elements for ba1 from rndbarr
    ran->rndbarr(xnd->ba2, xnd->i2);
    end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time1 = end1 - begin1;

    begin2 = std::chrono::high_resolution_clock::now();
    xnd->doand();
    end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time2 = end2 - begin2;

    begin232 = std::chrono::high_resolution_clock::now();
    xnd->doand32();
    end232 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time232 = end232 - begin232;

    begin3 = std::chrono::high_resolution_clock::now();
    xnd->door();
    end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time3 = end3 - begin3;

    begin332 = std::chrono::high_resolution_clock::now();
    xnd->door32();
    end332 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time332 = end332 - begin332;

    begin4 = std::chrono::high_resolution_clock::now();
    xnd->doxor();
    end4 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time4 = end4 - begin4;

    begin432 = std::chrono::high_resolution_clock::now();
    xnd->doxor32();
    end432 = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> time432 = end432 - begin432;

    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <float, milli> elapsed = finish - start;
    std::cout << "\nTime taken to generate the arrays: " << time1.count() << " milliseconds" << "\n\n"
        << "Time taken to compare and display the arrays using and: " << time2.count() << " milliseconds" << "\n\n"
        << "Time taken to use and with 4-byte arrays: " << time232.count() << " milliseconds" << "\n\n"
        << "Time taken to compare and display the arrays using or: " << time3.count() << " milliseconds" << "\n\n"
        << "Time taken to use or with 4-byte arrays: " << time332.count() << " milliseconds" << "\n\n"
        << "Time taken to compare and display the arrays using xor: " << time4.count() << " milliseconds" << "\n\n"
        << "Time taken to use xor with 4-byte arrays: " << time432.count() << " milliseconds" << "\n\n"
        << "Time taken to complete everything: " << elapsed.count() << " milliseconds" << "\n\n";

    delete xnd;
    delete ran;

    std::cout << "Press any key to close ";
    std::cin >> s;
}

rando::rando(void)
{
    std::cout << "Starting\n";
}// Initializes the class rando

rando::~rando(void)
{
    std::cout << "Closing";
}// Deconstructs rando

void rando::rndbarr(BYTE* barr, size_t size)
{
    NTSTATUS stat;// A variable named stat that can check the status of a line of code
    try
    {
        if (stat =// So long as nothing goes wrong in the following line, stat will be 0
            (BCryptGenRandom(NULL, barr, size, BCRYPT_USE_SYSTEM_PREFERRED_RNG)// Generates random numbers using BCRYPT_USE_SYSTEM_PREFERRED_RNG for barr by the value in size
                != 0))// If something does go wrong, the following happens
        {
            std::cout << stat;// Outputs the error
        }
    }

    catch (std::exception e1)
    {
        // Does nothing if an exception is thrown
    }
}

xorand::xorand(void)
{

}

xorand::~xorand(void)
{

}

void xorand::doand() 
{
    int x = 0, x2 = 0;
    while (x <= i2) 
    {
        if ((ba1[x] < 1) && (ba2[x] < 1))// Checks if the arrays are both 1
        {
            x2++;
        }
        x++;
    }
    std::cout << "Both arrays were less than 1 simultaneously " << x2 << "times.";
}

void xorand::door()
{
    int x = 0, x2 = 0;
    while (x <= i2)
    {
        if ((ba1[x] == 0) || (ba2[x] == 0))// Checks if either array is 0
        x2++;
        x++;
    }
    std::cout << "\nThe arrays have been successfully checked for 0, and " << x2 << " at least one of them was.\n";
}

void xorand::doxor() 
{
    int x = 0;
    while (x <= i2)
    {
        std::cout << "\n\nBefore: " << static_cast<unsigned>(ba1[x]) << ", " << static_cast<unsigned>(ba2[x]);
        ba1[x] ^= ba2[x];
        ba2[x] ^= ba1[x];
        // Swaps the values in the arrays
        std::cout << "\nAfter: " << static_cast<unsigned>(ba1[x]) << ", " << static_cast<unsigned>(ba2[x]);
        x++;
    }
            std::cout << "\nApplied xor\n";
}

void xorand::doand32()
{
    int x = 0, x2 = 0;
    while (x <= i24)
    {
        if ((ba14[x] < 1) && (ba24[x] < 1))
            x2++;
        x++;
    }
    std::cout << "Both arrays were less than 1 simultaneously " << x2 << "times.";
}

void xorand::door32()
{
    int x = 0, x2 = 0;
    while (x <= i24)
    {
        if ((ba14[x] == 0) || (ba24[x] == 0))
            x2++;
        x++;
    }
    std::cout << "\nThe arrays have been successfully checked for 0, and " << x2 << " times at least one of them was.\n";
}

void xorand::doxor32()
{
    int x = 0;
    while (x <= i24)
    {
        std::cout << "\n\nBefore: " << static_cast<unsigned>(ba14[x]) << ", " << static_cast<unsigned>(ba24[x]);
        ba14[x] ^= ba24[x];
        ba24[x] ^= ba14[x];
        std::cout << "\nAfter: " << static_cast<unsigned>(ba14[x]) << ", " << static_cast<unsigned>(ba24[x]);
        x++;
    }
    std::cout << "\nApplied xor\n";
}