/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <fstream>
#include "../../Sdl2/sdl2_setup.hpp"

void Menu::draw_menu(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    renderer->DrawText1(((screenWidth / 2) / 1.2) + 10, 0, "Bienvenue sur Arcade !"); // Title


}
