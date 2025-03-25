/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.hpp
*/

#pragma once

#include "../Menu.hpp"
#include "../../Sdl2/sdl2_setup.hpp"

class Sdl2Menu : public IMenuRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Menu(SDL2 *sdl2);
        ~Sdl2Menu() = default;

        MenuEvent pollEvent() override;
        void rep_event(MenuEvent event) override;
};
