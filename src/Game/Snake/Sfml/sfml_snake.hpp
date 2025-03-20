/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake_sfml.hpp
*/
#include "../Snake.hpp"

#pragma once

class SfmlSnake : public ISnakeRenderer
{
    private:
        Sfml *sfml;
    public:
        SfmlSnake(Sfml *sfml);
        ~SfmlSnake() = default;

        void print_map(std::string *map, int score, int lives) override;
};
