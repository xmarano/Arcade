/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_pacman.hpp
*/

#pragma once

#include "../Pacman.hpp"

class Sdl2Pacman : public IPacmanRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Pacman(SDL2 *sdl2);
        ~Sdl2Pacman() = default;

        void print_map(std::string *map, int score, int lives, int level, int highscore) override;
        PacmanEvent pollEvent(int ch) override;
};
