/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** ncurses.hpp
*/

#pragma once
#include "../../../include/Core/DisplayInterface.hpp"
#include <ncurses.h>
#include "../src/Core/Menu/ncurses/nc_menu.hpp"

class NcursesDisplay : public IDisplay
{
    NcursesMenu menuRenderer;

    public:
        IMenuRenderer* getMenuRenderer() override { return &menuRenderer; }
        void init() override;
        void close() override;
        void render(const GameState& state) override;
        void renderText(const std::string& text, int x, int y);
        int getInput() override;
        std::string getName() const override { return "Ncurses"; }
        int getScreenWidth() override;
        int getScreenHeight() override;
};
