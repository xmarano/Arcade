/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** launch_games.cpp
*/

#include "Launcher.hpp"

void Launcher::handle_events(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
    IGameModule* currentGame, int code)
{
    std::string newLib;

    if (code == 1) newLib = "./lib/arcade_ncurses.so";
    else if (code == 2) newLib = "./lib/arcade_sdl2.so";
    else if (code == 3) newLib = "./lib/arcade_sfml.so";
    currentDisplay->stop();
    IDisplayModule* newDisplay = displayLoader.getInstance(newLib);
    newDisplay->setGameModule(currentGame);
    newDisplay->init();
    currentDisplay = newDisplay;
}

void Launcher::go_pacman(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
    IGameModule*& currentGame, DLLoader<IGameModule>& gameLoader, int code)
{
    std::string newLib;

    if (code == CODE_NC_PACMAN) newLib = "./lib/arcade_ncurses.so";
    else if (code == CODE_SDL2_PACMAN) newLib = "./lib/arcade_sdl2.so";
    else if (code == CODE_SFML_PACMAN) newLib = "./lib/arcade_sfml.so";
    currentDisplay->stop();
    IDisplayModule* newDisplay = displayLoader.getInstance(newLib);
    IGameModule* pacmanGame = gameLoader.getInstance(PACMAN_GAME);
    newDisplay->setGameModule(pacmanGame);
    newDisplay->init();
    currentDisplay = newDisplay;
    currentGame = pacmanGame;
}

void Launcher::go_snake(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
    IGameModule*& currentGame, DLLoader<IGameModule>& gameLoader, int code)
{
    std::string newLib;

    if (code == CODE_NC_SNAKE) newLib = "./lib/arcade_ncurses.so";
    else if (code == CODE_SDL2_SNAKE) newLib = "./lib/arcade_sdl2.so";
    else if (code == CODE_SFML_SNAKE) newLib = "./lib/arcade_sfml.so";
    currentDisplay->stop();
    IDisplayModule* newDisplay = displayLoader.getInstance(newLib);
    IGameModule* snakeGame = gameLoader.getInstance(SNAKE_GAME);
    newDisplay->setGameModule(snakeGame);
    newDisplay->init();
    currentDisplay = newDisplay;
    currentGame = snakeGame;
}
