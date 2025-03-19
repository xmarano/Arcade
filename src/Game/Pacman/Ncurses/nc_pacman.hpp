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

        void print_map(std::string *map) override;
        // Autre methodes comunes a toutes les librairies graphiques pour Pacman
};
