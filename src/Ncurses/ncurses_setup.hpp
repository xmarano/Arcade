/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../IRenderer.hpp"

class Ncurses : public ADisplayModule, public IRenderer {
    public:
        Ncurses();
        ~Ncurses();
        void init() override;
        void stop() override;
        void display() override;

        void DrawText1(int pos_x, int pos_y, string mess) override;
        void DrawText2(int pos_x, int pos_y, string mess) override;

        // void Draw_Module1() override;
        // void Draw_Module2() override;
        // void Draw_Module3() override;

        void clearScreen() override;
        void refreshScreen() override;

        // Idendependant
        void setTerminalTitle(string name);

        int getScreenWidth() override;
        int getScreenHeight() override;
};
