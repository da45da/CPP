#include <iostream>
#include "Header.h"
using namespace std;

    /*  Damian Attia-Barillas
        Did this program compile? Yes
        Did this program run as expected? Yes
        Mark that you think you deserve. 99%

        1 I learned more about pointers and references, namely ways in which to use them

        I believe that 99% is reasonable because everything executes in an organised manner and I feel as though I understand what goes on

        Note: https://www.cplusplus.com/doc/tutorial/pointers/ gave thorough explinations with examples that greatly aided my learning for pointers. As for references, https://www.geeksforgeeks.org/pointers-vs-references-cpp/ was my main source of information. While I did research other sources, these two, that were provided for me, ended up being the most useful to me
    */

int main()// Declares that Main function of the program. Anything within its bounds is executed if possible and anything outside it will not
{
    string s;// Declares string s
    pointers();// Calls the function pointers()
    cout << "\r\n";// Displays a blank line
    references();
    cout << "\r\n";
    arrays();
    cout << "\r\n\n";// Displays 2 blank lines

    cout << "Enter something to close the program";// Prompts the user to close the program
    cin >> s;// Waits for user input before closing
}

void pointers()// Declares the void method pointers
{
    string s;
    int i1 = 24, foo, bar;// Declares integers i1, foo, and bar, while assigning i1 a value of 24;

    foo = (int)&i1;// Obtains i1's location in the memory as an int to be used as foo's value
    bar = i1;// Sets bar's value equal to i1's

    cout << "The value of i1 is " << bar << ", and its location in memory for this execution is " << foo << "\r\n";// Outputs the value and memory location of i1

    cout << "Thus ends pointers(), please write something to proceed ";// Promps the user for input
    cin >> s;// Waits for user input before proceeding
}

void references()
{
    string s;
    int i = 27;// Declares int i with a value of 27
    int& r = i;// Declares the integer reference r as a reference to i

    cout << "Integer r, as a reference of int i, has a value of the following: " << r << "\r\n";// Outputs the value of r, and subsequently i

    cout << "Thus ends references(), please write something to proceed ";
    cin >> s;
}

void arrays() 
{
    string s;
    int* i = new int[40]{ 32, 43, 654, 123, 12, 543 };// Declares an integer array pointer called i and assigns its first 6 values
    i[15] = 62;// Sets the 15th value of i to be 62

    cout << "The memory location of the 15th value in the array is " << (int)&i[15] << "\r\n";// Displays where the 15th element of i is in the computer's memory

    delete[] i;// Deletes i to prevent memory leaks

    cout << "Thus ends pointers(), please write something to proceed ";
    cin >> s;
}