/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** DisplayInterface.hpp
*/

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct GameState {
    std::vector<std::string> map;
    int score;
    int lives;
    int level;
    std::string gameName;
    // Ajouter d'autres éléments d'état au besoin
};

class IDisplay {
    public:
        virtual ~IDisplay() = default;
        virtual void init() = 0;
        virtual void close() = 0;
        virtual void render(const GameState& state) = 0;
        virtual int getInput() = 0;
        virtual std::string getName() const = 0;
};
