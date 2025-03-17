/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libfoo.cpp
*/

#include <iostream>

extern "C"
{
    __attribute__((constructor))
    void init() {
        std::cout << "[libfoo] Loading foo library ..." << std::endl;
    }

    __attribute__((destructor))
    void cleanup() {
        std::cout << "[libfoo] foo closing ..." << std::endl;
    }

    void myEntryPoint() {
        std::cout << "[libfoo] Entry point for foo !" << std::endl;
    }
}
