/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** game.hpp
*/

#pragma once

#include "../AGameModule.hpp"

class Game : public AGameModule {
    public:
        Game() {};
        ~Game() = default;
        void draw_menu() override = 0;
};
