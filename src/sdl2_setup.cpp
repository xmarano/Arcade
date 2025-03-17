/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.cpp
*/

#include "sdl2_setup.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

extern "C" IDisplayModule* create()
{
    return new Sdl2();
}

Sdl2::Sdl2() : ADisplayModule("Sdl2")
{
    return;
}

void Sdl2::init()
{
    //init sdl2
}

void Sdl2::display()
{
    //display sdl2
}

void Sdl2::stop()
{
    cout << "[SDL2] SDL2 stopping ..." << endl;
}
