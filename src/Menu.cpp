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
    renderer->DrawTitleMenu("Bienvenue sur Arcade !"); // Title

    // renderer->drawText(screenWidth / 2 - 10, startY, "Jeu disponible"); // Module 1
    // renderer->draw_box(screenWidth / 2 - 10, startY + lineHeight, 20, 1); // Box Module 1

    // renderer->drawText(screenWidth / 2 - 10, startY + lineHeight, "Profil du joueur"); // Module 2
    // renderer->draw_box(screenWidth / 2 - 10, startY + 2 * lineHeight, 20, 1); // Box Module 2

    // renderer->drawText(screenWidth / 2 - 10, startY + 2 * lineHeight, "Affichage"); // Module 3
    // renderer->draw_box(screenWidth / 2 - 10, startY + 3 * lineHeight, 20, 1); // Box Module 3
}
