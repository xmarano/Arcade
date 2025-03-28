/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Launcher.cpp
*/

#include "../../include/Core/Launcher.hpp"

IDisplay* Launcher::change_lib(IDisplay* current, int input)
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

Launcher::Launcher(const std::string& initialDisplayPath) : currentDisplay(displayLoader.load(initialDisplayPath)), isMenu(true) {
    currentDisplay->init();
}

Launcher::~Launcher()
{
    if (currentGame) {
        delete currentGame;
        currentGame = nullptr;
    }
    if (currentDisplay) {
        currentDisplay->close();
        delete currentDisplay;
        currentDisplay = nullptr;
    }
}

void Launcher::launchGame(int gameCode)
{
    if (currentDisplay) {
        currentDisplay->close();
        delete currentDisplay;
    }

    switch (gameCode) {
        case CODE_NC_PACMAN:
            currentDisplay = displayLoader.load("./lib/arcade_ncurses.so");
            currentGame = gameLoader.load("./lib/arcade_Pacman.so");
            break;
        case CODE_SDL2_PACMAN:
            currentDisplay = displayLoader.load("./lib/arcade_sdl2.so");
            currentGame = gameLoader.load("./lib/arcade_Pacman.so");
            break;
        case CODE_SFML_PACMAN:
            currentDisplay = displayLoader.load("./lib/arcade_sfml.so");
            currentGame = gameLoader.load("./lib/arcade_Pacman.so");
            break;
        case CODE_NC_SNAKE:
            currentDisplay = displayLoader.load("./lib/arcade_ncurses.so");
            currentGame = gameLoader.load("./lib/arcade_Snake.so");
            break;
        case CODE_SDL2_SNAKE:
            currentDisplay = displayLoader.load("./lib/arcade_sdl2.so");
            currentGame = gameLoader.load("./lib/arcade_Snake.so");
            break;
        case CODE_SFML_SNAKE:
            currentDisplay = displayLoader.load("./lib/arcade_sfml.so");
            currentGame = gameLoader.load("./lib/arcade_Snake.so");
            break;
        default:
            break;
    }
    if (currentDisplay)
        currentDisplay->init();
    isMenu = false;
}

int Launcher::run()
{
    while (true) {
        if (!isMenu) {
            int input = currentDisplay->getInput();
            if (input == -1)
                break;
            if (input >= 1 && input <= 3) {
                IDisplay* newDisplay = change_lib(currentDisplay, input);
                if (newDisplay) {
                    currentDisplay = newDisplay;
                    currentDisplay->init();
                }
                continue;
            }
            if (currentGame != nullptr) {
                currentGame->handleInput(input);
                GameState state = currentGame->update();
                currentDisplay->render(state);
            }
        } else {
            int ret = menu.draw_menu(currentDisplay);
            if (ret == -1)
                break;
            if (ret >= CODE_NC_PACMAN && ret <= CODE_SFML_SNAKE) {
                launchGame(ret);
            }
        }
    }
    return 0;
}
