/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../Pacman.hpp"

class NcursesPacman: public IPacmanRenderer
{
    private:
        Ncurses *nc;
    public:
        NcursesPacman(Ncurses *nc);
        ~NcursesPacman() = default;

        void print_map(std::string *map, int score, int lives, int level, int highscore) override;
        PacmanEvent pollEvent() override { return PacmanEvent::None; }
};
