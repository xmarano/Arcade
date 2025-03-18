/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../IRenderer.hpp"
#include <ncurses.h>

class Ncurses : public ADisplayModule, public IRenderer {
    private:
        int pos_x;
        int pos_y;
    public:
        Ncurses();
        ~Ncurses();
        void init() override;
        void stop() override;
        void display() override;

        void DrawTitleMenu() override;

        void Draw_Module1() override;
        void Draw_Module2() override;
        void Draw_Module3() override;

        void clearScreen() override;
        void refreshScreen() override;

        // Idendependant
        void setTerminalTitle(string name);

        void getScreenWidth() override;
        void getScreenHeight() override;
};
