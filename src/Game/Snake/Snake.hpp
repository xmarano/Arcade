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
        std::string *load_snake_map(std::string filename);
        // int check_eat_apple(char new_pos);
        bool check_game_over();
        // void end_of_level();
        std::string get_game_name() override { return "Snake"; }
    private:
        std::string *map;
        bool is_game_over;
        // std::pair<int, int> pos_player;
        // int score;
        // int highscore;
};

class ISnakeRenderer {
    public:
        virtual ~ISnakeRenderer() = default;

        virtual void print_map(string *map) = 0;
        virtual SnakeEvent pollEvent() = 0;
        virtual void quit() = 0;
};
