/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IDisplayModule.hpp
*/

#pragma once

using namespace std;
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <ncurses.h>

#include "IGameModule.hpp"

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual void display() = 0;
    virtual void setGameModule(IGameModule *game) = 0;
};
