/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Main.cpp
*/

#include "../include/Core/DisplayInterface.hpp"
#include "../include/Core/GameInterface.hpp"
#include "../include/Core/DLLoader.hpp"
#include "../include/Core/Menu.hpp"
#include "ArcadeException.hpp"
#include <iostream>
#include <filesystem>
#include "Launcher.hpp"

IDisplay* change_lib(IDisplay* current, int input)
{
    static DLLoader<IDisplay> loader;

    if (current) {
        current->close();
        delete current;
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
    bool isMenu = true;
    bool needRestart = false;
    std::string nextLib;

    try {
        if (argc == 2 && std::string(argv[1]) == "unitest")
            return 0;
        Parsing(argc, argv);
        DLLoader<IDisplay> displayLoader;
        DLLoader<IGame> gameLoader;
        IGame *game = nullptr;
        Menu menu;
        IDisplay* display = displayLoader.load(argv[1]);
        display->init();
        while (true) {
            if (isMenu == false) {
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
            } else {
                int ret = menu.draw_menu(display);
                if (ret == -1) break;
                if (ret == CODE_NC_PACMAN) {
                    display->close();
                    display = displayLoader.load("./lib/arcade_sdl2.so");
                    display->init();
                    game = gameLoader.load("./lib/arcade_Snake.so");
                    isMenu = false;
                }
            }
        }
        delete game;
        display->close();
        delete display;
    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}

// int main(int argc, char **argv)
// {
//     try {
//         if (argc == 2 && std::string(argv[1]) == "unitest")
//             return 0;
//         Parsing(argc, argv);
//         Launcher launcher(argv[1]);
//         return launcher.run();
//     } catch (ArcadeException &e) {
//         std::cerr << "Error: " << e.what() << std::endl;
//         return 84;
//     }
// }
