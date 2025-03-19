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

    renderer->DrawText1(4, 4, "Pacman");
    IPacmanRenderer* pacmanRenderer = renderer->getPacmanRenderer();
    if (pacmanRenderer == nullptr) {
        renderer->DrawText1(4, 8, "Error: pacmanRenderer is null");
        return;
    }
    pacmanRenderer->load_map_from_file("map.txt");
}
