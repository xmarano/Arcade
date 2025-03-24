/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../Snake.hpp"

class NcursesSnake: public ISnakeRenderer
{
    private:
        Ncurses *nc;
    public:
        NcursesSnake(Ncurses *nc);
        ~NcursesSnake() = default;

        void print_map() override;
        SnakeEvent pollEvent() override;
        void quit() override;
};
