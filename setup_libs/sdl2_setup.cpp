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
    if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0) {
        cout << "[SDL2] SDL2 failed to initialize: " << SDL_GetError() << endl;
        return;
    }
    //init sdl2
}

void Sdl2::display()
{
    //display sdl2
}

void Sdl2::stop()
{
    SDL_Quit();
    cout << "[SDL2] SDL2 stopping ..." << endl;
}
