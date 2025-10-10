// Iteration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../SplashScreen.h"
#include <iostream>

int main()
{
    displaySplashScreen("Iteration");

    // While loop - count and display 1-10
    int x = 1;
    while (x <= 10)
    {
        std::cout << x << std::endl;
        x = x + 1;
    }

    // Do While loop - count and display 1-10
    int y = 1;
    do
    {
        y = y + 1;
        std::cout << y << std::endl;
    } while (y <= 10);
    
    // For loop - count and display 1-10
    for (int i = 1; i <= 10; i++)
    {
        std::cout << i << std::endl;
    }


    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
