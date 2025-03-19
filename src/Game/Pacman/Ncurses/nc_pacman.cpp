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
                check_bonuses(this->map[x - 1][y]);
                this->map[x - 1][y] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.first = x - 1;
            }
            break;
        case KEY_DOWN:
            if (this->map[x + 1][y] != WALL) {
                check_bonuses(this->map[x + 1][y]);
                this->map[x + 1][y] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.first = x + 1;
            }
            break;
        case KEY_LEFT:
            if (this->map[x][y - 1] != WALL) {
                check_bonuses(this->map[y - 1][y]);
                this->map[x][y - 1] = PLAYER;
                this->map[x][y] = EMPTY;
                this->pos_player.second = y - 1;
            }
            break;
        case KEY_RIGHT:
            if (this->map[x][y + 1] != WALL) {
                check_bonuses(this->map[x][y + 1]);
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

// void NcursesPacman::game()
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

void NcursesPacman::check_bonuses(char new_pos)
{
    if (new_pos == COIN) {
        this->score += 10;
    } else if (new_pos == POWERUP) {
        this->score += 50;
        this->is_sous_frozen = true;
    }
    if new_pos == GHOST {
        this->lives -= 1;
        this->pos_player = DEFAULT_PLAYER_POSITION;
    }
    if new_pos == TELEPORT {
        if (this->pos_player != TELEPORT_1)
            this->pos_player = TELEPORT_1;
        else
            this->pos_player = TELEPORT_2;
    }
}