/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman.hpp
*/

#pragma once

#include <ncurses.h>
#include <fstream>
#include "../../IGameModule.hpp"
#include "../../ArcadeExeption.hpp"
#include "../../IRenderer.hpp"
#include "../../Ncurses/ncurses_setup.hpp"
#include "../../Sdl2/sdl2_setup.hpp"

    #define PLAYER 'C'
    #define WALL '#'
    #define GHOST 'G'
    #define COIN '*'
    #define EMPTY ' '
    #define POWERUP '@'
    #define TELEPORT 'T'

class Pacman : public IGameModule
{
    public:
        Pacman() = default;
        ~Pacman() = default;
        void draw_game(IRenderer *renderer) override;
};

class IPacmanRenderer {
    public:
        virtual ~IPacmanRenderer() = default;
        virtual int load_map_from_file(std::string filename) = 0;
        virtual void move_player() = 0;

        // Autre methodes comunes a toutes les librairies graphiques pour Pacman
};
