/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.hpp
*/

#pragma once

#include "../Menu.hpp"

class NcursesMenu : public IMenuRenderer
{
    private:
        int pos_x;
        int pos_y;
        Ncurses *nc;
    public:
        NcursesMenu(Ncurses* nc);
        ~NcursesMenu() = default;

        MenuEvent pollEvent() override;
        void rep_event(MenuEvent event) override;
};
