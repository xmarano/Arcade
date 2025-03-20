/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.hpp
*/

#pragma once

#include "../Menu.hpp"

class Sdl2Menu : public IMenuRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Menu(SDL2 *sdl2);
        ~Sdl2Menu() = default;

        // MenuEvent pollEvent() override;
};
