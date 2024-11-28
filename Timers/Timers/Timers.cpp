// Timers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

    /*  Damian Attia-Barillas
        Did this program compile? Yes
        Did this program run as expected? Yes
        Mark that you think you deserve. 99%

        1) Learned a bit about the thread header file and its applications (Such as sleep_for())

        I believe that 99% is reasonable because the thread is paused for the specified amount of time and the average time taken to execute the program
   
     Note: The average time to execute the program is 1.102 seconds
   */
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


int main()
{
    auto start = std::chrono::high_resolution_clock::now();// Declares a timer value named start and starts the clock
    auto finish = std::chrono::high_resolution_clock::now();
    start = std::chrono::high_resolution_clock::now();// Stops start's timer

    long l = 1100;
    std::cout << "Hello ";
    std::this_thread::sleep_for(std::chrono::milliseconds(l));
    std::cout << "World";
    // Displays Hello World with a 1.1 second gap in between

    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = finish - start;// Finds the elapsed time from the difference between the two time intervals
    std::cout << "\n\nElapsed time: " << elapsed_seconds.count() << "s\n";// Displays the time taken to execute the program

    return 0;
}