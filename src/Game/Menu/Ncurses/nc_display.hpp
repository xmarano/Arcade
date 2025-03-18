/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.hpp
*/

#pragma once

#include "../../../Ncurses/ncurses_setup.hpp"

class NcursesMenu : public IMenuRenderer
{
    public:
        NcursesMenu() = default;
        ~NcursesMenu() = default;
        void Draw_Module1() override;
        void Draw_Module2() override;
        void Draw_Module3() override;
};
