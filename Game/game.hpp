/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** game.hpp
*/

#pragma once

#include "../AGameModule.hpp"

class Game : public AGameModule {
    private:
        Menu *menu;
    public:
        Game() : menu(new Menu()) {};
        ~Game() = default;
        void draw_menu() override = 0;
};
