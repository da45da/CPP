// Namespaces.cpp : This file contains the 'main' function. Program execution begins and ends there.
//This file is not named Intro_C++.cpp, the precceding line was changed accordingly

	/*  Damian Attia-Barillas
		Did this program compile? Yes
		Did this program run as expected? Yes
		Mark that you think you deserve. 99%

		1 I learned more about namespaces: from how they're declared to how they're defined/used in a given scope

		I believe that 99% is reasonable because The code functions as I believe it to be intended, and I have commented on the changes I made
	*/

#include <iostream>
#include "Namespaces.h"// Created this header file, renamed it accordingly, and shifted the semicolon in accordance with changes below
using namespace std;// Added this so that I don't have to write std:: in front of everything that usually needs it

	int main()
	{
		string s1;
		test::HelloWorld();// Calls the instance of HelloWorld from the namespace test
		test2::HelloWorld();
		test3::HelloWorld();
		cout << "Press any key to exit. ";
		cin >> s1;
		return 0;
	}
	// Removed std:: from certain items as it is no longer required
	//main() could not be in a namespace without breaking the program

	void test::HelloWorld()
	{
	cout << "Hello World from test." << endl;
	}

	void test2::HelloWorld()
	{
		cout << "Hello World from test2." << endl;
	}

	void test3::HelloWorld()// Added explicit type void
	{
		cout << "Hello World from test3." << endl;
	}
	// Changed the namespaces from declarations to definitions as they are declared in the header file