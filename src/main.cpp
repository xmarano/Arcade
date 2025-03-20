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
#include <iostream>
#include <filesystem>

void handle_events(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& loader, IGameModule* currentGame, int code) //! A mettre ds une classe
{
    if (code > 0) {
        std::string newLib;
        if (code == 1)
            newLib = "./lib/arcade_ncurses.so";
        else if (code == 2)
            newLib = "./lib/arcade_sdl2.so";
        else if (code == 3)
            newLib = "./lib/arcade_sfml.so";
        currentDisplay->stop();
        IDisplayModule* newDisplay = loader.getInstance(newLib);
        newDisplay->setGameModule(currentGame);
        newDisplay->init();
        currentDisplay = newDisplay;
    }
}

void run_arcade(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& loader, IGameModule* currentGame) //! A mettre ds une classe
{
    bool running = true;
    int code = 0;

    while (running) {
        code = currentDisplay->display(); // Affiche le jeu (Menu)
        handle_events(currentDisplay, loader, currentGame, code); // Gere les event de swap de lib.
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
        Parsing(ac, av);
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
