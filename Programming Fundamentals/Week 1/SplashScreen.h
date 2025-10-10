#pragma once
// Ignore the following 3 lines, they are just here to show the splash screen
#include <thread>
#include <chrono>
#include <iostream>

// Splash screen (please ignore)
void displaySplashScreen(std::string name)
{
    int screenWidth = 80;
    int offsetLength = (screenWidth - name.length()) / 2;   // Integer division
    std::cout << R"( _______  _______ _________               ___    _______  _______  _______    ___   
(  ____ \(  ____ \\__   __/              /   )  (  __   )(  __   )/ ___   )  /   )  
| (    \/| (    \/   ) (                / /) |  | (  )  || (  )  |\/   )  | / /) |  
| (_____ | |         | |      _____    / (_) (_ | | /   || | /   |    /   )/ (_) (_ 
(_____  )| | ____    | |     (_____)  (____   _)| (/ /) || (/ /) |  _/   /(____   _)
      ) || | \_  )   | |                   ) (  |   / | ||   / | | /   _/      ) (  
/\____) || (___) |___) (___                | |  |  (__) ||  (__) |(   (__/\    | |  
\_______)(_______)\_______/                (_)  (_______)(_______)\_______/    (_))" << std::endl;

    for (int i = 0; i < offsetLength; i++)
        std::cout << "-";
    std::cout << " " << name << " ";
    for (int i = 0; i < offsetLength; i++)
        std::cout << "-";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    system("cls");
}

