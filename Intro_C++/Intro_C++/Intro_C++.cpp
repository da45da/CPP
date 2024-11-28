// Intro_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"// Lets the program know that there is a header file associated with the program
using namespace std;// Saves some space visually by negating the need for std:: while working with the console

    /*  Damian Attia-Barillas
		Did this program compile? Yes
		Did this program run as expected? Yes
		Mark that you think you deserve. 99%

		1 I learned how to make a header file  2) I learned how to access a header file from the main program

		I believe that 99% is reasonable because all 7 functions are declared/defined as expected and there are comments explaining everything

		Note: Strings, For Loops, and While Loops came from https://www.w3schools.com/cpp/default.asp because the original website did not have those activities
	*/

int main()
{
	int a = 1;
	int b = 4;
	int c = 3;
	string s;
	// Declares some variables to be used later in the program

	cout << "Hello world:\n";
	s1();
	cout << "Variables and Types:\n";
	s2();
	cout << "Arrays:\n";
	s3();
	cout << "Strings:\n";
	s4();
	cout << "For loops:\n";
	s5();
	cout << "While loops:\n";
	s6();
	cout << "Functions:\n";
	cout << s7(a, b, c);
	// Calls the 7 functions declared in the header and defined below

	cin >> s;// Waits for user input before closing
	return 0;// Returns 0 because Main is declared with an int
}

void s1()// Defines the function s1 below
{
	cout << "Hello World\n\n";// Displays Hello World with a blank space after
}

void s2()
{
	int a = 2, b = 3, c = 4;// Declares integers a, b, and c while assigning them values

	cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";// Displays the current values of the integers
	cout << "a + b = " << a + b << "\na + c = " << a + c << "\nb + c = " << b + c << "\na + b + c = " << a + b + c << "\n\n";// Displays all possible ways to add a b and c
}

void s3()
{
	char keys[6]// Declares the character array keys with 6 elements
		= { 'a','b','a','c','d','c' };// Assigns a value to each of the elements in keys
	cout << keys[2] << "\n\n";// Displays the 3rd element of keys (elements are numbered 0-5)
}

void s4() 
{
	string greeting = "Hello\n\n";// Declares string greeting and assigns it Hello
	cout << greeting;// Displays greeting
}

void s5() 
{
	for (int i = 0; i < 5; i++)// Declares a for loop that occurrs 5 times
	{
		cout << "Yes\n";// Displays Yes
	}
	cout << "\n";// With the last instance of \n, creates a blank line of space
}

void s6() 
{
	int i = 1;
	while (i < 6)// Declares a while loop for as long as i is less than 6
	{
		cout << i << "\n";// Displays the current value of i
		i++;// Increments i up by 1
	}
	cout << "\n";
}

int s7(int val1, int val2, int val3)
{
	return (val1 + val2 + val3);// Returns the sum of the three integers
}