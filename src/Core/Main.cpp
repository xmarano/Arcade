/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Main.cpp
*/

#include "../include/Core/DisplayInterface.hpp"
#include "../include/Core/GameInterface.hpp"
#include "../include/Core/DLLoader.hpp"
#include "ArcadeException.hpp"
#include <iostream>
#include <filesystem>

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

void Parsing(int argc, char **argv)
{
    if (argc != 2)
        throw ArcadeException("Usage: ./arcade ./lib/lib.so");

    std::string temp_file_path = argv[1];
    if (!std::filesystem::exists(temp_file_path))
        throw ArcadeException("Library not found");

    std::string file_path = temp_file_path.substr(temp_file_path.find_last_of("/") + 1);
    if (file_path != "arcade_ncurses.so" && file_path != "arcade_sfml.so" && file_path != "arcade_sdl2.so")
        throw ArcadeException("Wrong library");
}

int main(int argc, char **argv)
{
    try {
        if (argc == 2 && std::string(argv[1]) == "unitest")
            return 0;
        Parsing(argc, argv);

        DLLoader<IDisplay> displayLoader;
        DLLoader<IGame> gameLoader;

        IDisplay* display = displayLoader.load(argv[1]);
        // IGame *game = gameLoader.load("./lib/arcade_Menu.so");
        // IGame *game = gameLoader.load("./lib/arcade_Snake.so");
        IGame *game = gameLoader.load("./lib/arcade_Pacman.so");
 
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
    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
