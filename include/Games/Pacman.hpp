/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Pacman.hpp
*/

#pragma once
#include "../Core/GameInterface.hpp"
#include <vector>

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

class Pacman : public IGame {
    protected:
        GameState state;
        int score;
        int lives;
        int level;
        int highscore;
        bool is_sous_frozen;
        std::pair<int, int> pos_player;
        std::pair<int, int> pos_red_ghost;
        std::pair<int, int> pos_pink_ghost;
        std::pair<int, int> pos_blue_ghost;
        std::pair<int, int> pos_orange_ghost;
        std::vector<std::string> map;
        std::vector<std::string> original_map;
        std::vector<std::string> coin_map;
        clock_t phantom_clock, player_clock, frozen_clock;

    public:
        Pacman();
        GameState update() override;
        void handleInput(int key) override;
        std::string getName() const override { return "Pacman"; }
        void reset() override;
        // EntityType charToEntityType(char c) {
        //     switch (c) {
        //         case 'C': return EntityType::PLAYER;
        //         case '#': return EntityType::WALL;
        //         case '.': return EntityType::BONUS;
        //         case '@': return EntityType::POWERUP;
        //         case 'R': case 'P': case 'B': case 'O': return EntityType::ENEMY;
        //         default: return EntityType::EMPTY;
        //     }
        // }

    private:
        void loadMap();
        void movePlayer(int new_x, int new_y);
        int check_bonuses(char cell);
        bool win_condition();
        std::pair<int, int> move_ghost(std::pair<int, int> pos, char type);
        int manhattan_distance(std::pair<int, int> a, std::pair<int, int> b);
        bool is_valid_position(std::pair<int, int> pos);
        std::pair<int, int> random_move(std::pair<int, int> pos);
        void reset_positions();
        std::pair<int, int> chase_movement(std::pair<int, int> pos_ghost);
        std::pair<int, int> fear_movement(std::pair<int, int> pos_ghost);
};
