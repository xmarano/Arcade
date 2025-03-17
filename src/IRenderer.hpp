/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

#pragma once
#include <string>

class IRenderer {
    public:
        virtual ~IRenderer() = default;
        virtual void drawText(int x, int y, const std::string &text) = 0;
        virtual void clearScreen() = 0;
        virtual void refreshScreen() = 0;
        virtual int getScreenWidth() const = 0;
        virtual int getScreenHeight() const = 0;
};
