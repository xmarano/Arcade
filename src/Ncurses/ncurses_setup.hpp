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
    void drawText(int x, int y, const std::string &text) override;
    void clearScreen() override;
    void refreshScreen() override;
    int getScreenWidth() const override;
    int getScreenHeight() const override;
};
