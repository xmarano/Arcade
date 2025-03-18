/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"
#include "ArcadeExeption.hpp"
#include "Menu.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw ArcadeException("Usage: ./arcade ./lib/libncurses.so");

        DLLoader<IDisplayModule> loader;
        IDisplayModule *display = loader.getInstance(av[1]);

        Menu menu;
        display->setGameModule(&menu);

        display->init();
        display->display();
        display->stop();

        delete display;
        return 0;
    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
