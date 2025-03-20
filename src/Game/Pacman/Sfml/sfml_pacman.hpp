/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman_sfml.hpp
*/

#pragma once

#include "../Pacman.hpp"

class SfmlPacman : public IPacmanRenderer
{
    private:
        Sfml *sfml;
    public:
        SfmlPacman(Sfml *sfml);
        ~SfmlPacman() = default;

        void print_map(std::string *map, int score, int lives, int level, int highscore) override;
};
