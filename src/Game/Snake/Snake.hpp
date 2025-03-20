/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman.hpp
*/
#include <ncurses.h>
#include <fstream>
#include "../../IGameModule.hpp"
#include "../../ArcadeExeption.hpp"
#include "../../IRenderer.hpp"
#include "../../Ncurses/ncurses_setup.hpp"
#include "../../Sdl2/sdl2_setup.hpp"

#pragma once

    #define PLAYER '>'
    #define WALL '#'
    #define GHOST 'G' // rm
    #define COIN '*' // switch to apple
    #define EMPTY ' '
    #define POWERUP '@' // rm
    #define TELEPORT 'T' // rm
    #define MAP_HEIGHT 17
    #define DEFAULT_PLAYER_POSITION std::make_pair(9, 4)
    #define TELEPORT_1 std::make_pair(1, 11)
    #define TELEPORT_2 std::make_pair(22, 11)

class Snake : public IGameModule
{
    public:
        Snake();
        ~Snake() = default;
        void draw_game(IRenderer *renderer) override; // Royal delux

        void move_player();
        int load_map_from_file(std::string filename);
        int check_bonuses(char new_pos);
        std::string get_game_name() override { return "Snake"; }

    private:
        int score;
        int lives;
        int level;
        int highscore;
        bool is_sous_frozen;
        pair<int, int> pos_player;
        string* map;
};

class ISnakeRenderer {
    public:
        virtual ~ISnakeRenderer() = default;

        virtual void print_map(string *map, int score, int lives) = 0;
        // Autre methodes comunes a toutes les librairies graphiques pour Snake
};
