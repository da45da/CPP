  
    /*  Damian Attia-Barillas
        Did this program compile? Yes
        Did this program run as expected? Yes
        Mark that you think you deserve. 100%

        1) I learned how to make a DLL in c++  2) I learned how to use a DLL in combination with a header file and its client application  3) Learned how to generate a fibonacci sequence through code

        I believe that 100% is reasonable because I have learned from the given example, implimented it into code on my computer, and improved it to include user input
    */

#include <utility>
#include <limits.h>
#include "pch.h"
#include "MathLib.h"

static unsigned long long previous_;  
static unsigned long long current_;   
static unsigned index_;
//Variables used within the DLL


void fibonacci_init(const unsigned long long a, const unsigned long long b)
{
    index_ = 0;

    current_ = a;
    previous_ = b;
    // Changing these will result in a different sequence
}// This function must be called before any other function.

bool fibonacci_next()
{
    // check to see if we'd overflow result or position
    if ((ULLONG_MAX - previous_ < current_) ||
        (UINT_MAX == index_))
    {
        return false;
    }

    if (index_ > 0)
    {
        previous_ += current_;
    }
    std::swap(current_, previous_);
    // Furthers the sequence
    index_++;
    return true;
}


unsigned long long fibonacci_current()
{
    return current_;// Get the current value in the sequence.
}

unsigned fibonacci_index()
{
    return index_;// Get the current index position in the sequence.
}