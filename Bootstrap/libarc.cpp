/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libarc.cpp
*/

#include <iostream>

extern "C"
{
    __attribute__((constructor))
    void init() {
        std::cout << "[libarc] Loading arc library ..." << std::endl;
    }

    __attribute__((destructor))
    void cleanup() {
        std::cout << "[libarc] foo closing ..." << std::endl;
    }

    void myEntryPoint() {
        std::cout << "[libarc] Entry point for foo !" << std::endl;
    }
}
