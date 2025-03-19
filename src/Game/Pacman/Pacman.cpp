/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"
#include <fstream>

void Pacman::draw_game(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();
    IPacmanRenderer* pacmanRenderer = renderer->getPacmanRenderer();

    // renderer->DrawText1(screenWidth / 3, screenHeight / 2, "Pacman");

    // pacmanRenderer->load_map_from_file("map.txt");
}
