/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake.hpp
*/

#pragma once

#include <fstream>
#include "../../IGameModule.hpp"
#include "../../ArcadeExeption.hpp"
#include "../../IRenderer.hpp"
#include "../../Ncurses/ncurses_setup.hpp"
#include "../../Sdl2/sdl2_setup.hpp"
    #define SNAKE_MAP "Assets/Maps/snake_map.txt"

enum class SnakeEvent {
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

class Snake : public IGameModule {
    public:
        Snake();
        ~Snake() = default;
        int draw_game(IRenderer *renderer) override;

        int move_snake(ISnakeRenderer* snakeRenderer);
        // int load_map_from_file(std::string filename);
        // int check_eat_apple(char new_pos);
        // int win_condition();
        // void end_of_level();
        std::string get_game_name() override { return "Snake"; }
    private:
        // std::string *map;
        // std::pair<int, int> pos_player;
        // int score;
        // int lives;
        // int level;
        // int highscore;
        // bool is_sous_frozen;
        // std::pair<int, int> pos_blue_ghost;
        // std::pair<int, int> pos_orange_ghost;
        // std::pair<int, int> pos_pink_ghost;
        // std::pair<int, int> pos_red_ghost;
};

class ISnakeRenderer {
    public:
        virtual ~ISnakeRenderer() = default;

        virtual void print_map() = 0;
        virtual SnakeEvent pollEvent() = 0;
        virtual void quit() = 0;
};
