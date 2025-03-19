/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../../IRenderer.hpp"
#include "../Pacman.hpp"
#include <ncurses.h>

class NcursesPacman: public IPacmanRenderer
{
    private:
        Ncurses *nc;
        int score;
        int lives;
        int level;
        int highscore;
        std::pair<int, int> pos_player;
        std::string* map;
    public:
        NcursesPacman(Ncurses *nc);
        ~NcursesPacman() = default;
        void move_player() override;
        int load_map_from_file(std::string filename) override;
};
