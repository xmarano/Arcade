/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_pacman.cpp
*/

#include "nc_pacman.hpp"
#include "../../../ArcadeExeption.hpp"

NcursesPacman::NcursesPacman(Ncurses *nc) : nc(nc)
{
    this->score = 0;
    this->lives = 3;
    this->level = 1;
    this->highscore = 0;
    this->pos_player = std::make_pair(19, 13);
    load_map_from_file("src/Game/Pacman/pacman_map.txt");
    // for (int i = 0; i < MAP_HEIGHT; i++)
    // {
    //     std::cout << this->map[i] << std::endl;
    // }
}

void NcursesPacman::move_player()
{
    int ch = getch();
    int x = this->pos_player.first;
    int y = this->pos_player.second;

    switch (ch) {
        case KEY_UP:
            if (this->map[x - 1][y] != WALL) {
                // Check here if it was coin or powerup
                this->map[x - 1][y] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.first = x - 1;
            }
            break;
        case KEY_DOWN:
            if (this->map[x + 1][y] != WALL) {
                // Check here if it was coin or powerup
                this->map[x + 1][y] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.first = x + 1;
            }
            break;
        case KEY_LEFT:
            if (this->map[x][y - 1] != WALL) {
                // Check here if it was coin or powerup
                this->map[x][y - 1] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.second = y - 1;
            }
            break;
        case KEY_RIGHT:
            if (this->map[x][y + 1] != WALL) {
                // Check here if it was coin or powerup
                this->map[x][y + 1] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.second = y + 1;
            }
            break;
    }
}

int NcursesPacman::load_map_from_file(std::string filename)
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
