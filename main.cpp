/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"

int main(int ac, char **av)
{
    DLLoader<IDisplayModule> loader;
    IDisplayModule *module = loader.getInstance(av[1]);

    if (module) {
        cout << "Module name: " << module->getName() << endl;
        module->init();
        module->stop();
    }
    dlclose(module);
    return 0;
}
