// Data_Structres_c++2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

    /*  Damian Attia-Barillas
        Did this program compile? Yes
        Did this program run as expected? Yes
        Mark that you think you deserve. 100%

        1) Vectors are a handy alternative to arrays that can update their size as you go without needing to be copied/erased

        I believe that 100% is reasonable because the program has both an array and a vector for the structure Cars, the program runs as aesthetically pleasing as I can make it, and there are efficient comments
    */

#include <iostream>
#include <string>
#include <vector>
#include "Data_Structure.h"
using namespace std;

    int i1, i;
    Cars cars[3];// Declares an array of the struct Cars with 3 elements

int main()
{
    std::string s1;
    for (i1 = 0; i1 < 3; i1++)
    {
        cars[i1] = { "", "", 0, 0, (byte)0, (byte)0, (byte)0, (byte)0 };// While 0 is well within the scope of a byte, a cast is needed here for the bytes due to the nature of how I defined them
        getarr();
    }// Calls getarr() 3 times

    std::cout << "That ends the array portion. The following deals with vectors and will ignore your previous inputs.\n\n";
    getvec();

    std::cout << "\nPress any key to end: ";
    std::cin >> s1;
    //Prompts the user to close and waits for an input
}

int ints()
{
    int i1;
    std::string s1;
    bool b1 = false;

    while (not b1)
    {
        std::cin >> s1;

        try
        {
            i1 = stoi(s1);
            b1 = true;
        }
        catch (exception& err)// namespace std provides the definition for exception
        {
            std::cout << "Conversion failure: " << err.what() << "\n\n";// Notifies the user that an error occured and tells them what happened
        }
    }
    return i1;
}// For the purpose of this assignment, it would be pointless to declare this in a header file

void getarr()
{
    Cars car;// Declares a placeholder 

    std::cout << "Please enter a brand: ";
    std::cin >> car.brand;

    std::cout << "Enter model: ";
    std::cin >> car.model;

    std::cout << "Enter year: ";
    car.year = ints();

    std::cout << "Enter MSRP: ";
    car.MSRP = ints();

    std::cout << "Enter the number of tires: ";
    i = ints();
    car.tirenum = (std::byte)i;

    std::cout << "Enter the number of doors: ";
    i = ints();
    car.doornum = (std::byte)i;

    std::cout << "Enter the number of seats: ";
    i = ints();
    car.seats = (std::byte)i;

    std::cout << "Enter the horse power: ";
    i = ints();
    car.hp = (std::byte)i;
    // Gets a value for every variable in Cars
    //Strings are simply extracted from user input; ints do the same, but need the stoi() function to convert; and bytes follow suit with ints, but they also have casts

    std::cout << "\nHere is the car you generated:\n\n" << car.brand << " " << car.model << "\nYear: "
        << car.year << "\nMSRP: " << car.MSRP << "\nNumber of tires: "
        << static_cast<unsigned>(car.tirenum) << "\nNumber of doors: " << static_cast<unsigned>(car.doornum) << "\nNumber of seats: "
        << static_cast<unsigned>(car.seats) << "\nHorse power: " << static_cast<unsigned>(car.hp) << "\n\n";
    // Displays all of the input variables as one car's stats

    cars[i1] = { car.brand, car.model, car.year, car.MSRP, car.tirenum, car.doornum, car.seats, car.hp };
}

void getvec()
{
    int i2;
    i1 = 1;
    bool B = false, B1 = false;
    string s;
    vector <Cars> cars(1);

    while (not B)
    {
        i1--;

        std::cout << "\nPlease enter a brand: ";
        std::cin >> cars[i1].brand;

        std::cout << "Enter model: ";
        std::cin >> cars[i1].model;

        std::cout << "Enter year: ";
        cars[i1].year = ints();

        std::cout << "Enter MSRP: ";
        cars[i1].MSRP = ints();

        std::cout << "Enter the number of tires: ";
        i = ints();
        cars[i1].tirenum = (std::byte)i;

        std::cout << "Enter the number of doors: ";
        i = ints();
        cars[i1].doornum = (std::byte)i;

        std::cout << "Enter the number of seats: ";
        i = ints();
        cars[i1].seats = (std::byte)i;

        std::cout << "Enter the horse power: ";
        i = ints();
        cars[i1].hp = (std::byte)i;

    cout << "\nWould you like to enter another vehicle? Press 0 if not ";
    cin >> s;

    if (s == "0") 
    {
        B = true;
    }
    else
    {
    i1++;
    cars.resize(++i1);
    }
    };
    // Gets a value for every variable in Cars
    //Strings are simply extracted from user input; ints do the same, but need the stoi() function to convert; and bytes follow suit with ints, but they also have casts

        std::cout << "\nWould you like to view a car? Press 0 if not ";// Prompts the user to view a car
        cin >> s;

        if (s != "0")
    while (not B1)
    {
        std::cout << "\n\nWhich car would you like to view? ";// Prompts the user to input
        i2 = ints();

        if (i2 <= i1)
        {
            std::cout << "\n\nHere is the car you generated:\n\n" << cars[i2].brand << " " << cars[i2].model << "\nYear: "
                << cars[i2].year << "\nMSRP: " << cars[i2].MSRP << "\nNumber of tires: "
                << static_cast<unsigned>(cars[i2].tirenum) << "\nNumber of doors: " << static_cast<unsigned>(cars[i2].doornum) << "\nNumber of seats: "
                << static_cast<unsigned>(cars[i2].seats) << "\nHorse power: " << static_cast<unsigned>(cars[i2].hp) << "\n\n";
        }// If the user enters a valid car number, the console displays it
        else
            std::cout << "Please enter a valid number next time, your first car is stored in '0'\n\n";

        std::cout << "Would you like to see another vehicle? Press 0 if not ";// Prompts the user to view another car
        cin >> s;

        if (s == "0")
        {
            B1 = true;
        }// Ends the loop if the user inputs 0
    }
}