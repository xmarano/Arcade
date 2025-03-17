/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** menu.hpp
*/

#pragma once

#include "../Game/game.hpp"

class Menu : public Game {
    public:
        Menu() = default;
        ~Menu() = default;
        void draw_menu() override;
};
