/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** snake.cpp
*/
#include "Snake.hpp"
#include <fstream>

void Snake::draw_game(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();
    ISnakeRenderer* snakeRenderer = renderer->getSnakeRenderer();

    while (this->lives > 0) {
        clear();
        snakeRenderer->print_map(this->map, this->score, this->lives);
        move_player();
        refresh();
    }
    this->highscore = this->score;
    this->score = 0;
}

Snake::Snake()
{
    this->score = 0;
    this->lives = 3;
    this->level = 1;
    this->highscore = 0;
    this->pos_player = DEFAULT_PLAYER_POSITION;
    load_map_from_file("src/Game/Snake/snake_map.txt");
}

void Snake::move_player()
{
    int ch = getch();
    int x = this->pos_player.first;
    int y = this->pos_player.second;

    switch (ch) {
        case KEY_UP:
            if (this->map[x - 1][y] != WALL) {
                if (check_bonuses(this->map[x - 1][y]) == 0) {
                    this->map[x - 1][y] = PLAYER;
                    this->map[x][y] = EMPTY;
                    this->pos_player.first = x - 1;
                }
            }
            break;
        case KEY_DOWN:
            if (this->map[x + 1][y] != WALL) {
                if (check_bonuses(this->map[x + 1][y]) == 0) {
                    this->map[x + 1][y] = PLAYER;
                    this->map[x][y] = EMPTY;
                    this->pos_player.first = x + 1;
                }
            }
            break;
        case KEY_LEFT:
            if (this->map[x][y - 1] != WALL) {
                if (check_bonuses(this->map[y - 1][y]) == 0) {
                    this->map[x][y - 1] = PLAYER;
                    this->map[x][y] = EMPTY;
                    this->pos_player.second = y - 1;
                }
            }
            break;
        case KEY_RIGHT:
            if (this->map[x][y + 1] != WALL) {
                if (check_bonuses(this->map[x][y + 1]) == 0) {
                    this->map[x][y + 1] = PLAYER;
                    this->map[x][y] = EMPTY;
                    this->pos_player.second = y + 1;
                }
            }
            break;
    }
}

int Snake::load_map_from_file(std::string filename)
{
    std::string line;
    std::ifstream file(filename);
    int i = 0;

    if (!file.is_open()) {
        throw ArcadeException("Invalid file map.");
        return -1;
    }
    this->map = new std::string[MAP_HEIGHT];

    while (std::getline(file, line)) {
        if (i < MAP_HEIGHT) {
            this->map[i].assign(line);
            i++;
        } else {
            break;
        }
    }
    file.close();
    return 0;
}

// void Snake::game()
// {
//     int ch = 0;

//     while (ch != 27) {
//         for (int i = 0; i < MAP_HEIGHT; i++) {
//             this->nc->DrawText1(0, i, this->map[i]);
//         }
//         ch = getch();
//         move_player();
//     }
// }

int Snake::check_bonuses(char new_pos)
{
    if (new_pos == COIN) {
        this->score += 10;
        return 0;
    } else if (new_pos == POWERUP) {
        this->score += 50;
        this->is_sous_frozen = true;
        return 0;
    }
    if (new_pos == GHOST) {
        this->lives -= 1;
        this->pos_player = DEFAULT_PLAYER_POSITION;
        return 1;
    }
    if (new_pos == TELEPORT) {
        if (this->pos_player != TELEPORT_1)
            this->pos_player = TELEPORT_1;
        else
            this->pos_player = TELEPORT_2;
        return 1;
    }
    return 0;
}
