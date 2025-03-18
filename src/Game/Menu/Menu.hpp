/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.hpp
*/

#pragma once

#include "../../IGameModule.hpp"

class Menu : public IGameModule
{
    public:
        Menu() = default;
        ~Menu() = default;
        void draw_game(IRenderer *renderer) override;
};

class IMenuRenderer {
    public:
        virtual ~IMenuRenderer() = default;
        virtual void Draw_Module1() = 0;
        virtual void Draw_Module2() = 0;
        virtual void Draw_Module3() = 0;
};
