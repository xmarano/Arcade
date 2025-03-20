/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_Snake.hpp
*/
#include "../Snake.hpp"

#pragma once

class Sdl2Snake : public ISnakeRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Snake(SDL2 *sdl2);
        ~Sdl2Snake() = default;

        void print_map(std::string *map, int score, int lives) override;
};
