/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../IRenderer.hpp"
#include "../Game/Menu/Menu.hpp"

class Ncurses : public ADisplayModule, public IRenderer
{
    private:
        IMenuRenderer* menuRenderer = nullptr;
    public:
        Ncurses();
        ~Ncurses();
        void init() override;
        void stop() override;
        void display() override;

        virtual IMenuRenderer* getMenuRenderer() override { return menuRenderer; }
        virtual IPacmanRenderer* getPacmanRenderer() override { return nullptr; }
        void DrawText1(int pos_x, int pos_y, string mess) override;
        void DrawText2(int pos_x, int pos_y, string mess) override;

        void clearScreen() override;
        void refreshScreen() override;

        // Idendependant
        void setTerminalTitle(string name);

        int getScreenWidth() override;
        int getScreenHeight() override;
};
