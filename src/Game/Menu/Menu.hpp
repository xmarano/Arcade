/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.hpp
*/

#pragma once

#include "../../IGameModule.hpp"
#include "../../ArcadeExeption.hpp"
#include <fstream>
#include "../../Sdl2/sdl2_setup.hpp"
#include "../Pacman/Pacman.hpp"
#include "../../Ncurses/ncurses_setup.hpp"

class Pacman;

class Menu : public IGameModule
{
    private:
        Pacman *pacman;
        int selectedOption;
    public:
        Menu();
        ~Menu();
        void draw_game(IRenderer *renderer) override;
        void modules(IRenderer *renderer);
        void DisplayText(IRenderer *renderer, string text, int module, int height);
        int DisplayModules1(IRenderer *renderer);
        int DisplayModules2(IRenderer *renderer);
        int DisplayModules3(IRenderer *renderer);
};

class IMenuRenderer {
    public:
        virtual ~IMenuRenderer() = default;
        virtual void Draw_Module1() = 0;
        virtual void Draw_Module2() = 0;
        virtual void Draw_Module3() = 0;
};
