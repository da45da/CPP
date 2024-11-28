// Data_Structures_c++_Timed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

    /*  Damian Attia-Barillas
        Did this program compile? Yes
        Did this program run as expected? Yes
        Mark that you think you deserve. 99%

        1) Learned about the random header file  2) Learned how to apply map/unordered_map to a program

        I believe that 99% is reasonable because 

        Note: Average times for various test points:

                                            Ordered       Unordered

        Inserting 100,000 elements:         5.50 seconds, 4.60 seconds
        Searching 100 random elements:      0.46 seconds, 0.51 seconds
        Deleting 100 random elements:       7.73ms,       6.78ms
        Searching 500 random elements:      0.61 seconds, 0.63 seconds
        Deleting 500 random elements:       36.31ms,      32.9ms
    */

#include <iostream>
#include <string>
#include <chrono>
#include <map>// Includes maps and unorderd_maps
#include <random>// Includes a set of functions that enables pseudo-random values to be declared
#include "Data_Structures_c++_Timed.h"
using namespace std;

int main()
{
    std::string s;
    ordered::mapget();

    unordered::mapget();

    std::cout << "Press any key to close";
    std::cin >> s;
    return 0;
}

int i = 100000, in = 500;

void ordered::mapget()
{
    auto start = std::chrono::high_resolution_clock::now();// Declares a timer value named start and starts the clock
    auto finish = std::chrono::high_resolution_clock::now();
    start = std::chrono::high_resolution_clock::now();// Stops start's timer

    std::string s;
    std::map<std::string, int> map_example;// Declares the map map_example with a string for its key(s) and an int for its value(s)

    int i1 = 0, i2 = 0;
    while (i1 < i)
    {
        s = ("map_example" + to_string(i1 + 1));
        map_example.insert(pair<string, int>(s, i1));// Inserts a new key/value pair inti map_example with s/i1 as its elements
        i1++;
    };

    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = finish - start;// Finds the elapsed time from the difference between the two time intervals
    std::cout << "Elapsed time to insert 100,000 elements for an ordered map: " << elapsed_seconds.count() << "s\n";// Displays the time taken to execute the program

    start = std::chrono::high_resolution_clock::now();

    i2 = 0;
    std::string s2 = "";
    while (i2 < in)
    {
        s2 = ("map_example" + to_string(random()));
        std::cout << map_example.find(s2)->second << "\n";// Finds an element in map_example using s2 as the key  and displays it
        i2++;
    };
    finish = std::chrono::high_resolution_clock::now();

    elapsed_seconds = finish - start;
    std::cout << "\nElapsed time to search " << in << " elements for an ordered map: " << elapsed_seconds.count() << "s\n";


    start = std::chrono::high_resolution_clock::now();
    i2 = 0;

    while (i2 < in)
    {
        s2 = ("map_example" + to_string(random()));
        map_example.erase(s2);// Erases the key/value pair indicated by s2
        i2++;
    };
    finish = std::chrono::high_resolution_clock::now();

    chrono::duration <float, milli> elapsed = finish - start;
    std::cout << "\nElapsed time to delete " << in << " elements for an ordered map: " << elapsed.count() << "ms\n";
}

void unordered::mapget()
{
    auto start = std::chrono::high_resolution_clock::now();// Declares a timer value named start and starts the clock
    auto finish = std::chrono::high_resolution_clock::now();
    start = std::chrono::high_resolution_clock::now();// Stops start's timer
    std::string s;
    std::map<std::string, int> unordered_map_example;

    int i1 = 0, i2 = 0;
    while (i1 < i)
    {
        s = ("unordered_map_example" + to_string(i1 + 1));
        unordered_map_example.insert(pair<string, int>(s, i1));
        i1++;
    };

    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = finish - start;// Finds the elapsed time from the difference between the two time intervals
    std::cout << "\n\nElapsed time to insert 100,000 elements for an unordered map: " << elapsed_seconds.count() << "s\n";// Displays the time taken to execute the program

    start = std::chrono::high_resolution_clock::now();

    i2 = 0;
    std::string s2 = "";
    while (i2 < in)
    {
        s2 = ("unordered_map_example" + to_string(random()));
        std::cout << unordered_map_example.find(s2)->second << "\n";
        i2++;
    };
    finish = std::chrono::high_resolution_clock::now();

    elapsed_seconds = finish - start;
    std::cout << "\nElapsed time to search " << in << " elements for an unordered map: " << elapsed_seconds.count() << "s\n";


    start = std::chrono::high_resolution_clock::now();

    i2 = 0;
    while (i2 < in)
    {
        s2 = ("unordered_map_example" + to_string(random()));
        unordered_map_example.erase(s2);
        i2++;
    };
    finish = std::chrono::high_resolution_clock::now();

    chrono::duration <float, milli> elapsed = finish - start;
    std::cout << "\nElapsed time to delete " << in << " elements for an unordered map: " << elapsed.count() << "ms\n";
}

int random() 
{
    std::random_device rd;// Declares a random agent
    std::mt19937// Generates a numeric value
        gen(rd());// Bases that value on the random rd
    std::uniform_int_distribution<> dis(1, 100000);// Sets a case for a scope between 1 and 100000
   
    return dis(gen);// Uses the random numeric property of gen for the scope of dis, generating a number between 1 and 100000
}