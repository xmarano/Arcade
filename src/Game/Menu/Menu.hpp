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
    public:
        Menu();
        ~Menu();
        void draw_game(IRenderer *renderer) override;
        void modules(IRenderer *renderer);
};

class IMenuRenderer {
    public:
        virtual ~IMenuRenderer() = default;
        virtual void Draw_Module1() = 0;
        virtual void Draw_Module2() = 0;
        virtual void Draw_Module3() = 0;
};
