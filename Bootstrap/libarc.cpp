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

Libarc::Libarc() : ADisplayModule("libarc")
{
    return;
}

void Libarc::init()
{
    cout << "[libarc] Entry point for libarc !" << endl;
}

void Libarc::stop()
{
    cout << "[libarc] libarc stopping ..." << endl;
}
