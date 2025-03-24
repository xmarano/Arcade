/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ADisplayModule.hpp
*/

#pragma once

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

    #define CODE_NC_PACMAN 4
    #define CODE_SDL2_PACMAN 5
    #define CODE_SFML_PACMAN 6
    #define CODE_NC_SNAKE 7
    #define CODE_SDL2_SNAKE 8
    #define CODE_SFML_SNAKE 9

    #define PACMAN_GAME "./lib/arcade_pacman.so"
    #define SNAKE_GAME "./lib/arcade_snake.so"

class ADisplayModule : public IDisplayModule
{
    protected:
        IGameModule *gameModule;
    public:
        ADisplayModule(const std::string &moduleName) : name(moduleName), gameModule(nullptr) {}
        ~ADisplayModule() = default;
        void setGameModule(IGameModule *game) override { gameModule = game; }
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual int display() = 0;
    private:
        std::string name;
};
