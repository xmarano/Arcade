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
    #define RED_GHOST 'R'
    #define PINK_GHOST 'P'
    #define BLUE_GHOST 'B'
    #define ORANGE_GHOST 'O'
    #define COIN '.'
    #define EMPTY ' '
    #define POWERUP '@'
    #define TELEPORT 'T'
    #define MAP_HEIGHT 25
    #define DEFAULT_PLAYER_POSITION std::make_pair(18, 11)
    #define RED_GHOST_POS std::make_pair(11, 9)
    #define PINK_GHOST_POS std::make_pair(11, 13)
    #define BLUE_GHOST_POS std::make_pair(11, 12)
    #define ORANGE_GHOST_POS std::make_pair(11, 10)
    #define TELEPORT_1 std::make_pair(11, 1)
    #define TELEPORT_2 std::make_pair(11, 22)
    #define DEFAULT_MAP "Assets/Maps/pacman_map.txt"

enum class PacmanEvent {
    None,
    Quit,
    SwapToNcurses,
    SwapToSdl2,
    SwapToSfml,
    BackToMenu,
    UP,
    Down,
    Right,
    Left
};

class Pacman : public IGameModule
{
    public:
        Pacman();
        ~Pacman() = default;
        int draw_game(IRenderer *renderer) override; // Royal delux

        int move_player(IPacmanRenderer* pacmanRenderer);
        int load_map_from_file(std::string filename);
        int check_bonuses(char new_pos);
        std::string get_game_name() override { return "Pacman"; }
        int win_condition();
        void end_of_level();
        void pacmanHighStats(string stats);
        int get_score() { return this->score; }
        int get_lives() { return this->lives; }
        int get_level() { return this->level; }
        int get_highscore() { return this->highscore; }
        int manhattan_distance(std::pair<int, int> a, std::pair<int, int> b);

    private:
        int score;
        int lives;
        int level;
        int highscore;
        bool is_sous_frozen;
        pair<int, int> pos_player;
        // pair<int, int> pos_red_ghost;
        // pair<int, int> pos_pink_ghost;
        // pair<int, int> pos_blue_ghost;
        // pair<int, int> pos_orange_ghost;
        string* map;
};

class IPacmanRenderer {
    public:
        virtual ~IPacmanRenderer() = default;

        virtual void print_map(string *map, int score, int lives, int level, int highscore) = 0;
        virtual PacmanEvent pollEvent() = 0;
        virtual void quit() = 0;
        // Autre methodes comunes a toutes les librairies graphiques pour Pacman
};
