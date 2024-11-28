/*  Damian Attia-Barillas
    Did this program compile? Yes
    Did this program run as expected? Yes
    Mark that you think you deserve. 99%

    1) Learned how to generate a random number through a class  2) Learned how to generate a random byte array through a class  3) Learned that not all libraries are included by default in c++

    I believe that 99% is reasonable because the class works as intended and it it implemented into main to the best of my ability
*/

#include "Random_header.h"// Required headers are declared in here

int main()
{
    std::string s;
    int i = 0, i1, i2 = 1000, i3;
    rando *ran = new rando();
    i1 = ran->random(0, 1000);// Generates i1's value based on the retuened value from random
    std::cout << "Number successfully generated: " << i1 << "\n\n";

    byte *ba = new byte [i2];
    ran->rndbarr(ba, i2);// Generates elements for ba from rndbarr

    while (i <= i2) 
    {
        std::cout << static_cast<unsigned>(ba[i]) << "\n";
        i++;
    }

    delete[] ba;
    delete ran;

    std::cin >> s;
}

rando::rando(void) 
{
    std::cout << "Starting\n";
}// Initializes the class rando

rando::~rando(void)
{
    std::cout << "Closing";
}// Deconstructs rando once its operation is complete and notifies the user

int rando::random(int min, int max) 
{
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);// 0, UINT_MAX
   
    return dis(gen);// Uses gen for the scope of dis, returning a random number between min and max
}

void rando::rndbarr(byte* barr, size_t size)
{
    NTSTATUS stat;// A variable named stt that can check the status of a line of code
    try
    {
        if (stat =// So long as nothing goes wrong in the following line, stat will be 0
            (BCryptGenRandom( NULL, barr, size, BCRYPT_USE_SYSTEM_PREFERRED_RNG)// Generates the number of random bytes using BCRYPT_USE_SYSTEM_PREFERRED_RNG for the array brought in through barr indicated by the value brought in through size
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