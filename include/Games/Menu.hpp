/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Menu.hpp
*/
#include "../Core/GameInterface.hpp"

#pragma once

class Menu : public IGame {
    public:
        Menu();
        GameState update() override;
        void handleInput(int key) override;
        std::string getName() const override { return "Menu"; }
        void reset() override;

    private:
        int selectedGame;
        std::vector<std::string> gameList;
};
