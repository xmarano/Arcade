/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.hpp
*/

#pragma once

#include "../../../Sdl2/sdl2_setup.hpp"

class Sdl2Menu : public IMenuRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Menu(SDL2 *sdl2);
        ~Sdl2Menu() = default;
        void Draw_Module1() override;
        void Draw_Module2() override;
        void Draw_Module3() override;
};
