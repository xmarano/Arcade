/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.hpp
*/

#pragma once

#include "../../ADisplayModule.hpp"
#include "../../IRenderer.hpp"
#include "../../../IGameModule.hpp"

#define PLAYER 'C'
#define WALL '#'
#define GHOST 'G'
#define COIN '*'
#define EMPTY ' '
#define POWERUP '@'
#define TELEPORT 'T'

class Pacman_Game: public IGameModule
{
    public:
        Pacman_Game();
        ~Pacman_Game();
        void init();
        void stop();
        void display();
        void setGameModule(IGameModule *game) { gameModule = game; }
        void move_player();
        int load_map_from_file(std::string filename);
    private:
        IGameModule *gameModule;
        IRenderer *renderer;
        int score;
        int lives;
        int level;
        int highscore;
        std::pair<int, int> pos_player;
        std::string* map;

};
