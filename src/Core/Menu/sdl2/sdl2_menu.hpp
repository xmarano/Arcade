/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.hpp
*/

#pragma once

#include "../../../../include/Core/Menu.hpp"

class Sdl2Menu : public IMenuRenderer
{
    public:
        Sdl2Menu();
        ~Sdl2Menu() = default;

        MenuEvent pollEvent() override;
        void DrawText1(string text, int module, int height) override;
};
