/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"
#include "ArcadeExeption.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw ArcadeException("Usage: ./arcade ./lib/library.so");
        DLLoader<IDisplayModule> loader;

        IDisplayModule *module = loader.getInstance(av[1]);
        if (module) {
            module->init();
            module->display();
            module->stop();
        }
        dlclose(module);
        return 0;
    } catch (ArcadeException &e) {
        cerr << "Error: " << e.what() << endl;
        return 84;
    }
}
