/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.hpp
*/

#pragma once

#include "../../../../include/Core/Menu.hpp"

class NcursesMenu : public IMenuRenderer
{
    private:
        int pos_x;
        int pos_y;
    public:
        NcursesMenu();
        ~NcursesMenu() = default;

        MenuEvent pollEvent() override;
        void DrawText1(int pos_x, int pos_y, string text) override;
};
