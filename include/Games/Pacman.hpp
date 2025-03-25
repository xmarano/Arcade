/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Pacman.hpp
*/

#pragma once
#include "../Core/GameInterface.hpp"

class Pacman : public IGame {
    protected:
        GameState state;
        int score;
        int lives;
        int level;
        std::vector<std::string> map;
    public:
        Pacman();
        GameState update() override;
        void handleInput(int key) override;
        std::string getName() const override { return "Pacman"; }
        void reset() override;
    private:
        void loadMap();
        // void moveGhosts();
};
