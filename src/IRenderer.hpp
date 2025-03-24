/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

#pragma once

#include <iostream>

class IMenuRenderer;
class IPacmanRenderer;
class ISnakeRenderer;

class IRenderer {
    public:
        virtual ~IRenderer() = default;
        virtual IMenuRenderer* getMenuRenderer() = 0;
        virtual IPacmanRenderer* getPacmanRenderer() = 0;
        virtual ISnakeRenderer* getSnakeRenderer() = 0;

        virtual void DrawText1(int pos_x, int pos_y, std::string mess) = 0; // Font text.ttf
        virtual void DrawText2(int pos_x, int pos_y, std::string mess) = 0; // Font goofy.ttf
        virtual void DrawText3(int pos_x, int pos_y, std::string mess) = 0; // Font arial.ttf
        virtual void DrawText4(int pos_x, int pos_y, std::string mess) = 0; // Font little.ttf
        virtual void DrawText5(int pos_x, int pos_y, std::string mess) = 0; // Font arcade.ttf

        virtual void clearScreen() = 0;
        virtual void refreshScreen() = 0;

        virtual int getScreenWidth() = 0;
        virtual int getScreenHeight() = 0;
};
