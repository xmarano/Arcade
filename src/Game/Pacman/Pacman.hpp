/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman.hpp
*/

#pragma once

#include "../../IGameModule.hpp"
#include "../../ArcadeExeption.hpp"

#define PLAYER 'C'
#define WALL '#'
#define GHOST 'G'
#define COIN '*'
#define EMPTY ' '
#define POWERUP '@'
#define TELEPORT 'T'

class Pacman : public IGameModule
{
    private:
        IRenderer *renderer;
    public:
        Pacman() = default;
        ~Pacman() = default;
        void draw_game(IRenderer *renderer) override;
};

class IPacmanRenderer {
    public:
        virtual ~IPacmanRenderer() = default;

        virtual void Draw_Player() = 0;
        virtual void Draw_Ghost() = 0;
        virtual void Draw_Coin() = 0;
        virtual void Draw_Powerup() = 0;

        virtual int load_map_from_file(std::string filename) = 0;
        virtual void move_player() = 0;
};
