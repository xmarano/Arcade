/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Launcher.cpp
*/

#include "Launcher.hpp"

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

void Launcher::changeDisplay(int displayCode)
{
    if (!currentDisplay)
        return;
    IDisplay* newDisplay = nullptr;
    switch (displayCode) {
        case 1: newDisplay = displayLoader.load("./lib/arcade_ncurses.so"); break;
        case 2: newDisplay = displayLoader.load("./lib/arcade_sdl2.so"); break;
        case 3: newDisplay = displayLoader.load("./lib/arcade_sfml.so"); break;
        default: return;
    }
    currentDisplay->close();
    delete currentDisplay;
    currentDisplay = newDisplay;
    currentDisplay->init();

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
        // ... autres cas
    }

    if (currentDisplay) currentDisplay->init();
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
                changeDisplay(input);
                continue;
            }
            if (currentGame) {
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
