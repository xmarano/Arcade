/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** GameInterface.hpp
*/

#pragma once
#include "DisplayInterface.hpp"

class IGame {
    public:
        virtual ~IGame() = default;
        virtual GameState update() = 0;
        virtual void handleInput(int key) = 0;
        virtual std::string getName() const = 0;
        virtual void reset() = 0;
};
