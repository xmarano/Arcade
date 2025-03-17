/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../Ncurses/nc_menu.hpp"

class Ncurses : public ADisplayModule {
    public:
        Ncurses();
        ~Ncurses() = default;
        void init() override;
        void stop() override;
        void display() override;
};
