/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Pacman.cpp
*/

#include "../../../include/Games/Pacman.hpp"
#include <fstream>

Pacman::Pacman()
{
    reset();
}

void Pacman::reset()
{
    score = 0;
    lives = 3;
    level = 1;
    loadMap();
}

GameState Pacman::update()
{
    // moveGhosts();
    cout << "Pacman update" << endl;
    state = {map, score, lives, level, getName()};
    return state;
}

void Pacman::handleInput(int key)
{
    switch(key) {
        case 0: /* UP */    break;
        case 1: /* DOWN */  break;
        case 2: /* LEFT */  break;
        case 3: /* RIGHT */ break;
    }
}

void Pacman::loadMap() {
    // Chargement original adapté
    std::ifstream file("Assets/Maps/pacman_map.txt");
    // ... code original ...
}

extern "C" IGame* create()
{
    return new Pacman();
}
