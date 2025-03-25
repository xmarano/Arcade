/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"
#include "ArcadeExeption.hpp"
#include "Game/Menu/Menu.hpp"
#include "Launcher.hpp"
#include "ADisplayModule.hpp"
#include <iostream>
#include <filesystem>

void run_arcade(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
    IGameModule*& currentGame, DLLoader<IGameModule>& gameLoader)
{
    bool running = true;
    int code = 0;
    Launcher launcher;

    while (running) {
        // get data
        // process data
        // update display
        code = currentDisplay->display();
        if (code > 0 && code < 4) {
            launcher.handle_events(currentDisplay, displayLoader, currentGame, code);
        } else if (code >= CODE_NC_PACMAN && code <= CODE_SFML_PACMAN) {
            launcher.go_pacman(currentDisplay, displayLoader, currentGame, gameLoader, code);
        } else if (code == CODE_NC_SNAKE || code == CODE_SDL2_SNAKE || code == CODE_SFML_SNAKE) {
            launcher.go_snake(currentDisplay, displayLoader, currentGame, gameLoader, code);
        }
    }
}

void Parsing(int ac, char **av)
{
    if (ac != 2)
        throw ArcadeException("Usage: ./arcade ./lib/lib.so");

    std::string temp_file_path = av[1];
    if (!std::filesystem::exists(temp_file_path))
        throw ArcadeException("Library not found");

    std::string file_path = temp_file_path.substr(temp_file_path.find_last_of("/") + 1);
    if (file_path != "arcade_ncurses.so" && file_path != "arcade_sfml.so" && file_path != "arcade_sdl2.so")
        throw ArcadeException("Wrong library");
}

int main(int ac, char **av)
{
    try {
        if (ac == 2 && std::string(av[1]) == "unitest")
            return 0;
        Parsing(ac, av);
        DLLoader<IDisplayModule> displayLoader;
        DLLoader<IGameModule> gameLoader;
        IGameModule* currentGame = new Menu();
        IDisplayModule* currentDisplay = displayLoader.getInstance(av[1]);
        currentDisplay->setGameModule(currentGame);
        currentDisplay->init();

        run_arcade(currentDisplay, displayLoader, currentGame, gameLoader);

        currentDisplay->stop();
        delete currentGame;
        return 0;
    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
