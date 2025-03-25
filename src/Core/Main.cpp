/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Main.cpp
*/

#include "../include/Core/DisplayInterface.hpp"
#include "../include/Core/GameInterface.hpp"
#include "../include/Core/DLLoader.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    try {
        DLLoader<IDisplay> displayLoader;
        DLLoader<IGame> gameLoader;

        auto display = displayLoader.load(argv[1]);
        auto game = gameLoader.load("./lib/arcade_Pacman.so");

        display->init();

        while(true) {
            int input = display->getInput();
            if(input == -1) break;
            game->handleInput(input);
            GameState state = game->update();
            display->render(state);
        }
        display->close();
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
