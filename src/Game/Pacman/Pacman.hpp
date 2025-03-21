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
    #define COIN '.'
    #define EMPTY ' '
    #define POWERUP '@'
    #define TELEPORT 'T'
    #define MAP_HEIGHT 25
    #define DEFAULT_PLAYER_POSITION std::make_pair(18, 11)
    #define TELEPORT_1 std::make_pair(11, 1)
    #define TELEPORT_2 std::make_pair(11, 22)
    #define DEFAULT_MAP "Assets/Maps/pacman_map.txt"

enum class PacmanEvent {
    None,
    Quit,
    SwapToNcurses,
    SwapToSdl2,
    SwapToSfml,
    BackToMenu
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
        int get_score() { return this->score; }
        int get_lives() { return this->lives; }
        int get_level() { return this->level; }
        int get_highscore() { return this->highscore; }

    private:
        int score;
        int lives;
        int level;
        int highscore;
        bool is_sous_frozen;
        pair<int, int> pos_player;
        string* map;
};

class IPacmanRenderer {
    public:
        virtual ~IPacmanRenderer() = default;

        virtual void print_map(string *map, int score, int lives, int level, int highscore) = 0;
        virtual PacmanEvent pollEvent(int ch) = 0;
        // Autre methodes comunes a toutes les librairies graphiques pour Pacman
};
