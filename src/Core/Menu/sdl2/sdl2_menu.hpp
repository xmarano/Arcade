/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.hpp
*/

#pragma once

#include "../../../../include/Core/Menu.hpp"
#if defined(__linux__)
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL.h>
#elif defined(__APPLE__)
    #include <SDL_ttf.h>
    #include <SDL.h>
#endif

class SDL2Display;

class Sdl2Menu : public IMenuRenderer
{
    private:
        SDL2Display *display;
        int pos_x;
        int pos_y;
    public:
        Sdl2Menu(SDL2Display *disp);
        ~Sdl2Menu() = default;

        MenuEvent pollEvent() override;
        void DrawText1(int pos_x, int pos_y, string text) override;
};
