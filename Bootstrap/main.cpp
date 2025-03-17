/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"

int main()
{
    DLLoader<IDisplayModule> loader;
    IDisplayModule *module = loader.getInstance("./libfoo.so");

    if (module) {
        cout << "Module name: " << module->getName() << endl;
        module->init();
        module->stop();
    }
    dlclose(module);
    IDisplayModule *module2 = loader.getInstance("./libarc.so");
    if (module2) {
        cout << "Module name: " << module2->getName() << endl;
        module2->init();
        module2->stop();
    }
    dlclose(module2);
    return 0;
}
