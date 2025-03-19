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
        void draw_game();
        // Autre methodes comunes a toutes les librairies graphiques pour Pacman
};
