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

    renderer->DrawText(((screenWidth / 2) / 1.2) + 10, 0, "Bienvenue sur Arcade !"); // Title

}
