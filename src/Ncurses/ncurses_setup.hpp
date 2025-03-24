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
#include "../Game/Pacman/Pacman.hpp"
#include "../DLLoader.hpp"

class Ncurses : public ADisplayModule, public IRenderer
{
    private:
        IMenuRenderer* menuRenderer = nullptr;
        IPacmanRenderer* pacmanRenderer = nullptr;
        ISnakeRenderer* snakeRenderer = nullptr;
    public:
        Ncurses();
        ~Ncurses();
        void init() override;
        void stop() override;
        int display() override;

        virtual IMenuRenderer* getMenuRenderer() override { return menuRenderer; }
        virtual IPacmanRenderer* getPacmanRenderer() override { return pacmanRenderer; }
        virtual ISnakeRenderer* getSnakeRenderer() override { return snakeRenderer; }

        void DrawText1(int pos_x, int pos_y, string mess) override;
        void DrawText2(int pos_x, int pos_y, string mess) override { return DrawText1(pos_x, pos_y, mess); }
        void DrawText3(int pos_x, int pos_y, string mess) override { return DrawText1(pos_x, pos_y, mess); }
        void DrawText4(int pos_x, int pos_y, string mess) override { return DrawText1(pos_x, pos_y, mess); }
        void DrawText5(int pos_x, int pos_y, string mess) override { return DrawText1(pos_x, pos_y, mess); }

        void clearScreen() override;
        void refreshScreen() override;

        // Idendependant
        void setTerminalTitle(string name);

        int getScreenWidth() override;
        int getScreenHeight() override;
};
