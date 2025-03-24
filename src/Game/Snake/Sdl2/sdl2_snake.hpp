/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_pacman.hpp
*/

#pragma once

#include "../Snake.hpp"

class Sdl2Snake : public ISnakeRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Snake(SDL2 *sdl2);
        ~Sdl2Snake() = default;

        void print_map() override;
        SnakeEvent pollEvent() override;
        void quit() override;
};
