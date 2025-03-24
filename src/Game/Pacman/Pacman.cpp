/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Pacman.cpp
*/

#include "Pacman.hpp"
#include <fstream>

int Pacman::draw_game(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();
    IPacmanRenderer* pacmanRenderer = renderer->getPacmanRenderer();
    int ret = 0;

    while (this->lives > 0) {
        // pacmanRenderer->print_map(this->map, this->score, this->lives, this->level, this->highscore);
        renderer->DrawText1(0, 0, "Pacman");
        ret = move_player(pacmanRenderer);
        if (ret == 1) return 1;
        if (ret == 2) return 2;
        if (ret == 3) return 3;
        if (win_condition() == 1) {
            this->level += 1;
            load_map_from_file(DEFAULT_MAP);
            this->pos_player = DEFAULT_PLAYER_POSITION;
            break;
        }
    }
    end_of_level();
    return 0;
}

Pacman::Pacman()
{
    this->score = 0;
    this->lives = 3;
    this->level = 1;
    this->highscore = 0;
    this->pos_player = DEFAULT_PLAYER_POSITION;
    load_map_from_file(DEFAULT_MAP);
}

int Pacman::move_player(IPacmanRenderer* pacmanRenderer)
{
    int x = this->pos_player.first;
    int y = this->pos_player.second;

    PacmanEvent ev = pacmanRenderer->pollEvent();

    switch (ev) {
        case PacmanEvent::UP:
            if (this->map[x - 1][y] != WALL) {
                if (check_bonuses(this->map[x - 1][y]) == 0) {
                    this->map[x - 1][y] = PLAYER;
                    this->pos_player.first = x - 1;
                }
                this->map[x][y] = EMPTY;
            }
            break;
        case PacmanEvent::Down:
            if (this->map[x + 1][y] != WALL) {
                if (check_bonuses(this->map[x + 1][y]) == 0) {
                    this->map[x + 1][y] = PLAYER;
                    this->pos_player.first = x + 1;
                }
                this->map[x][y] = EMPTY;
            }
            break;
        case PacmanEvent::Left:
            if (this->map[x][y - 1] != WALL) {
                if (check_bonuses(this->map[x][y - 1]) == 0) {
                    this->map[x][y - 1] = PLAYER;
                    this->pos_player.second = y - 1;
                }
                this->map[x][y] = EMPTY;
            }
            break;
        case PacmanEvent::Right:
            if (this->map[x][y + 1] != WALL) {
                if (check_bonuses(this->map[x][y + 1]) == 0) {
                    this->map[x][y + 1] = PLAYER;
                    this->pos_player.second = y + 1;
                }
                this->map[x][y] = EMPTY;
            }
            break;
        default:
            if (ev == PacmanEvent::Quit)
                pacmanRenderer->quit();
            if (ev == PacmanEvent::SwapToNcurses)
                return 1;
            if (ev == PacmanEvent::SwapToSdl2)
                return 2;
            if (ev == PacmanEvent::SwapToSfml)
                return 3;
            break;
    }
    return 0;
}

int Pacman::load_map_from_file(std::string filename)
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

int Pacman::check_bonuses(char new_pos)
{
    if (new_pos == COIN) {
        this->score += (10 * level);
        return 0;
    } else if (new_pos == POWERUP) {
        this->score += (50 * level);
        this->is_sous_frozen = true;
        return 0;
    }
    if (new_pos == GHOST) {
        this->lives -= 1;
        this->pos_player = DEFAULT_PLAYER_POSITION;
        return 1;
    }
    if (new_pos == TELEPORT) {
        if (this->pos_player == std::make_pair(TELEPORT_1.first, TELEPORT_1.second + 1)) {
            this->pos_player = TELEPORT_2;
            this->pos_player.second -= 2;
        } else {
            this->pos_player = TELEPORT_1;
            this->pos_player.second += 1;
        }
        this->map[pos_player.first][pos_player.second] = PLAYER;
        return 1;
    }
    return 0;
}

int Pacman::win_condition()
{
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < this->map[i].length(); j++) {
            if (this->map[i][j] == COIN)
                return 0;
        }
    }
    return 1;
}

void Pacman::end_of_level()
{
    if (this->lives == 0) {
        this->lives = 3;
        this->highscore = this->score;
        this->score = 0;
        this->level = 1;
    } else {
        this->level += 1;
    }
}

extern "C" {
    IGameModule *create() {
        return new Pacman();
    }
}
