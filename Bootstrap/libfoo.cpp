/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libfoo.cpp
*/

#include "libfoo.hpp"

extern "C" IDisplayModule* create() {
    return new Libfoo();
}

void Libfoo::init()
{
    cout << "[libfoo] Entry point for libfoo !" << endl;
}

void Libfoo::stop()
{
    cout << "[libfoo] libfoo stopping ..." << endl;
}

const string &Libfoo::getName() const
{
    static const string name = "libfoo";
    return name;
}
