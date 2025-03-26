/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** ncurses.hpp
*/

#pragma once
#include "../../../include/Core/DisplayInterface.hpp"
#include <ncurses.h>

class NcursesDisplay : public IDisplay
{
    public:
        void init() override;
        void close() override;
        void render(const GameState& state) override;
        int getInput() override;
        std::string getName() const override { return "Ncurses"; }
};
