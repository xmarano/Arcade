/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman_sfml.hpp
*/

#pragma once

#include "../Snake.hpp"

class SfmlSnake : public ISnakeRenderer
{
    private:
        Sfml *sfml;
    public:
        SfmlSnake(Sfml *sfml);
        ~SfmlSnake() = default;

        void print_map(string *map) override;
        SnakeEvent pollEvent() override;
        void quit() override;
};
