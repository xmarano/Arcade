/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "libarc.hpp"
#include "libfoo.hpp"

using namespace std;

int main()
{
    const char *libs[] = {"./libfoo.so", "./libarc.so"};
    void *handle;
    typedef IDisplayModule* (*CreateFunc)();

    for (int i = 0; i < sizeof(libs) / sizeof(libs[0]); i++) {
        handle = dlopen(libs[i], RTLD_LAZY);
        if (!handle) {
            cerr << "Error: " << dlerror() << endl;
            continue;
        }
        CreateFunc create = (CreateFunc)dlsym(handle, "create");
        if (!create) {
            cerr << "Error: " << dlerror() << endl;
            dlclose(handle);
            continue;
        }
        IDisplayModule *module = create();
        module->init();
        module->stop();
        cout << "Module name: " << module->getName() << endl;
        delete module;
        dlclose(handle);
    }
    return 0;
}
