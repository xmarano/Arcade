/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libarc.cpp
*/

#include "libarc.hpp"

extern "C" IDisplayModule* create() {
    return new Libarc();
}

void Libarc::init()
{
    cout << "[libarc] Entry point for libarc !" << endl;
}

void Libarc::stop()
{
    cout << "[libarc] libarc stopping ..." << endl;
}

const string &Libarc::getName() const
{
    static const string name = "libarc";
    return name;
}
