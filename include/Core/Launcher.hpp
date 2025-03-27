/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Launcher.hpp
*/

#include "../include/Core/DisplayInterface.hpp"
#include "../include/Core/GameInterface.hpp"
#include "../include/Core/DLLoader.hpp"
#include "../include/Core/Menu.hpp"
#include "ArcadeException.hpp"
#include <iostream>
#include <filesystem>

class Launcher {
    private:
        DLLoader<IDisplay> displayLoader;
        DLLoader<IGame> gameLoader;
        IDisplay* currentDisplay;
        IGame* currentGame;
        Menu menu;
        bool isMenu;
    public:
        Launcher(const std::string& initialDisplayPath);
        ~Launcher();
        int run();
    private:
        void launchGame(int gameCode);
        IDisplay *change_lib(IDisplay *current, int input);
};
