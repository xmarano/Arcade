/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <fstream>
#include "../../Sdl2/sdl2_setup.hpp"
#include "../Pacman/Pacman.hpp"

void Menu::modules(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    IMenuRenderer* menuRenderer = renderer->getMenuRenderer();
    menuRenderer->Draw_Module1();
}

void Menu::draw_game(IRenderer *renderer)
{
    Pacman pacman;

    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    renderer->DrawText1(((screenWidth / 2) / 1.2) + 10, 0, "Bienvenue sur Arcade !"); // Title
    pacman.draw_game(renderer);
    // modules(renderer);
}
