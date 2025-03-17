/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include <iostream>
#include <dlfcn.h>

using namespace std;

int main()
{
    const char *libs[] = {"./libfoo.so", "./libarc.so"};
    void *handle;
    void (*myEntryPoint)();

    for (int i = 0; i < sizeof(libs) / sizeof(libs[0]); i++) {
        handle = dlopen(libs[i], RTLD_LAZY);
        if (!handle) {
            cerr << "Error: " << dlerror() << endl;
            continue;
        }
        myEntryPoint = (void (*)())dlsym(handle, "myEntryPoint");
        myEntryPoint();
        dlclose(handle);
    }
    return 0;
}
