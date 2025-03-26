/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Menu.cpp
*/

#include "../../../include/Games/Menu.hpp"

Menu::Menu() : selectedGame(0) {
    gameList = {"Pacman", "Snake"};
}

GameState Menu::update() {
    GameState state;
    state.entities.clear();
    return state;
}

void Menu::handleInput(int key)
{
    switch (key) {
        case 5: // Flèche haut
            if (selectedGame > 0) selectedGame--;
            break;
        case 6: // Flèche bas
            if (selectedGame < (int)gameList.size() - 1) selectedGame++;
            break;
        case 10: // Entrée
            // Charger le jeu sélectionné
            break;
    }
}

void Menu::reset() {
    selectedGame = 0;
}

extern "C" IGame* create() {
    return new Menu();
}
