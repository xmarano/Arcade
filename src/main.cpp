/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"
#include "ArcadeExeption.hpp"
#include "Game/Menu/Menu.hpp"

// void DLLoader<IDisplayModule>::changeLibrary(IDisplayModule*& currentDisplay, std::string newLibraryPath)
// {
//     DLLoader<IDisplayModule> loader;
//     IDisplayModule* newDisplay = loader.getInstance(newLibraryPath);

//     if (currentDisplay) {
//         currentDisplay->stop();
//         delete currentDisplay;
//     }
//     currentDisplay = newDisplay;
//     currentDisplay->init();
// }

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw ArcadeException("Usage: ./arcade ./lib/libncurses.so");

        DLLoader<IDisplayModule> loader;
        IDisplayModule *current_display = loader.getInstance(av[1]);
        ADisplayModule::setCurrentDisplayModule(current_display);
        bool running = true;

        Menu menu;
        current_display->setGameModule(&menu);

        current_display->init();
        while (running) {
            current_display->display();
        }
        current_display->stop();

        delete current_display;
        return 0;
    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
