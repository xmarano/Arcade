/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu()
{
    pacman = new Pacman();
}

Menu::~Menu()
{
    delete pacman;
}

void Menu::modules(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    IMenuRenderer* menuRenderer = renderer->getMenuRenderer();
    menuRenderer->Draw_Module1();
}

void Menu::draw_game(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    string title = "Bienvenue sur Arcade !";
    string title_1 = "Jeux disponibles:";
    string title_2 = "Joueur:";
    string title_3 = "Affichage:";

    renderer->DrawText1(((screenWidth / 2) - (title.length() / 2)), (screenHeight / 10 * 0), title);
    renderer->DrawText1((((screenWidth / 3) / 2) - (title_1.length() / 2)), (screenHeight / 10 * 1), title_1);
    renderer->DrawText1((((screenWidth / 1) / 2) - (title_2.length() / 2)), (screenHeight / 10 * 1), title_2);
    renderer->DrawText1((((screenWidth / 3) * 2.5) - (title_3.length() / 2)), (screenHeight / 10 * 1), title_3);

    pacman->draw_game(renderer);
    modules(renderer);
}
