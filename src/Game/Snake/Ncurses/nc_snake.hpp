/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/
#include "../Snake.hpp"

#pragma once

class NcursesSnake: public ISnakeRenderer
{
    private:
        Ncurses *nc;
    public:
        NcursesSnake(Ncurses *nc);
        ~NcursesSnake() = default;

        void print_map(std::string *map, int score, int lives) override;
        // Autre methodes comunes a toutes les librairies graphiques pour Snake
};
