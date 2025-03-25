/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Main.cpp
*/

#include "../include/Core/DisplayInterface.hpp"
#include "../include/Core/GameInterface.hpp"
#include "../include/Core/DLLoader.hpp"
#include <iostream>

IDisplay* change_lib(IDisplay* current, int input) {
    static DLLoader<IDisplay> loader; // Garde le loader en vie

    if (current) {
        current->close();
        delete current; // Supprime l'instance manuellement
    }

    if (input == 1) {
        return loader.load("./lib/arcade_ncurses.so");
    } else if (input == 2) {
        return loader.load("./lib/arcade_sdl2.so");
    } else if (input == 3) {
        return loader.load("./lib/arcade_sfml.so");
    }
    return nullptr;
}

int main(int argc, char** argv) {
    try {
        DLLoader<IDisplay> displayLoader;
        DLLoader<IGame> gameLoader;

        IDisplay* display = displayLoader.load(argv[1]);
        IGame* game = gameLoader.load("./lib/arcade_Pacman.so");

        display->init();

        while (true) {
            int input = display->getInput();
            if (input == -1)
                break;

            if (input >= 1 && input <= 3) {
                IDisplay* newDisplay = change_lib(display, input);
                if (newDisplay) {
                    display = newDisplay;
                    display->init();
                }
                continue;
            }

            game->handleInput(input);
            GameState state = game->update();
            display->render(state);
        }
        display->close();
        delete display;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
