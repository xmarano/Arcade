/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule.hpp
*/

#pragma once

using namespace std;
#include <SDL.h>
// ⬇ FIX crash mouli ⬇ //
#if defined(__linux__)
    #include <SDL2/SDL_ttf.h>
#elif defined(__APPLE__)
    #include <SDL_ttf.h>
#endif
#include <ncurses.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "IGameModule.hpp"

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual int display() = 0;
        virtual void setGameModule(IGameModule *game) = 0;
};
