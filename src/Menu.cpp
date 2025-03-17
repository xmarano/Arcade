/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <fstream>

void Menu::draw_menu(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    int startY = screenHeight / 4;
    int lineHeight = screenHeight / 10;

    renderer->drawText(screenWidth / 2 - 10, startY, "1. Jouer au jeu X");
    renderer->drawText(screenWidth / 2 - 10, startY + lineHeight, "2. Changer de bibliothèque graphique");
    renderer->drawText(screenWidth / 2 - 10, startY + 2 * lineHeight, "3. Quitter");
}
