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
        void Draw_Module1() override;
        void Draw_Module2() override;
        void Draw_Module3() override;
};
