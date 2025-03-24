/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Launcher.hpp
*/

#include "DLLoader.hpp"
#include "ArcadeExeption.hpp"
#include "Game/Menu/Menu.hpp"
#include "ADisplayModule.hpp"

class Launcher {
    public:
        void handle_events(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
            IGameModule* currentGame, int code);
        void go_pacman(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
            IGameModule*& currentGame, DLLoader<IGameModule>& gameLoader, int code);
        void go_snake(IDisplayModule*& currentDisplay, DLLoader<IDisplayModule>& displayLoader,
            IGameModule*& currentGame, DLLoader<IGameModule>& gameLoader, int code);
};
