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
        bool is_sous_frozen;
        std::pair<int, int> pos_player;
        std::string* map;
    public:
        NcursesPacman(Ncurses *nc);
        ~NcursesPacman() = default;
        void move_player() override;
        int load_map_from_file(std::string filename) override;
        void check_bonuses(char new_pos);
        // Autre methodes comunes a toutes les librairies graphiques pour Pacman
};
