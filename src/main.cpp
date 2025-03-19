/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** main.cpp
*/

#include "DLLoader.hpp"
#include "ArcadeExeption.hpp"
#include "Game/Menu/Menu.hpp"
#include "ADisplayModule.hpp"

bool handle_events(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& loader, IGameModule* currentGame) //! A mettre ds une classe
{
    Event event = currentDisplay->pollEvent();

    if (event == Event::Quit)
        return false;
    if (event == Event::SwitchToSDL2 || event == Event::SwitchToNCurses) {
        std::string newLib;
        if (event == Event::SwitchToSDL2)
            newLib = "./lib/arcade_sdl2.so";
        else
            newLib = "./lib/arcade_ncurses.so";
        currentDisplay->stop();
        IDisplayModule* newDisplay = loader.getInstance(newLib);
        newDisplay->setGameModule(currentGame);
        newDisplay->init();
        currentDisplay = newDisplay;
    }
    return true;
}

void run_arcade(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& loader, IGameModule* currentGame) //! A mettre ds une classe
{
    bool running = true;

    while (running) {
        currentDisplay->display(); // Affiche le jeu (Menu)
        running = handle_events(currentDisplay, loader, currentGame); // Gere les event de swap de lib.
    }
}

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw ArcadeException("Usage: ./arcade ./lib/libncurses.so");
        DLLoader<IDisplayModule> loader;
        IGameModule* currentGame = new Menu(); // Lance le menu au démarrage
        IDisplayModule* currentDisplay = loader.getInstance(av[1]);
        currentDisplay->setGameModule(currentGame);
        currentDisplay->init();

        run_arcade(currentDisplay, loader, currentGame); // Boucle des jeux

        currentDisplay->stop();
        delete currentGame;
        return 0;
    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
