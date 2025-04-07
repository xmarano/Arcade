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

// Définition des types d'éléments
enum EntityType {
    WALL,
    PLAYER,
    ENEMY,
    COIN,
    POWERUP,
    TELEPORT,
    EMPTY,
    BONUS
};

struct Entity {
    char element;   // Type de l'élément (ex: WALL, PLAYER)
    int x, y;          // Position
    int red, green, blue, alpha; // color
    // Optionnel : données supplémentaires (ex: couleur, état)
};

struct GameState {
    std::vector<Entity> entities; // Tous les éléments à afficher
    int score;
    int lives;
    int level;
    bool is_game_over;
    std::string gameName;          // Pour adapter le thème graphique
};

class IMenuRenderer;

class IDisplay {
    public:
        virtual ~IDisplay() = default;
        virtual void init() = 0;
        virtual void close() = 0;
        virtual void render(const GameState& state) = 0;
        virtual int getInput() = 0;
        virtual string getName() const = 0;
        virtual IMenuRenderer* getMenuRenderer() = 0;
        virtual int getScreenWidth() = 0;
        virtual int getScreenHeight() = 0;
};
