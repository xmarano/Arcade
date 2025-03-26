/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Pacman.cpp
*/

#include "../../../include/Games/Pacman.hpp"
#include <fstream>
#include <algorithm>

Pacman::Pacman()
{
    reset();
}

void Pacman::reset()
{
    score = 0;
    lives = 3;
    level = 1;
    highscore = 0;
    is_sous_frozen = false;
    pos_player = DEFAULT_PLAYER_POSITION;
    pos_red_ghost = RED_GHOST_POS;
    pos_pink_ghost = PINK_GHOST_POS;
    pos_blue_ghost = BLUE_GHOST_POS;
    pos_orange_ghost = ORANGE_GHOST_POS;
    loadMap();
}

GameState Pacman::update() {
    // [...] (déplacements, logique du jeu)
    if (win_condition() == 1) {
        level += 1;
        this->map = this->original_map;
        pos_player = DEFAULT_PLAYER_POSITION;
    }
    pos_red_ghost = move_ghost(pos_red_ghost, RED_GHOST);
    pos_pink_ghost = move_ghost(pos_pink_ghost, PINK_GHOST);
    pos_blue_ghost = move_ghost(pos_blue_ghost, BLUE_GHOST);
    pos_orange_ghost = move_ghost(pos_orange_ghost, ORANGE_GHOST);
    handleInput(1);

    // Conversion de la carte en entités génériques
    state.entities.clear();
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            Entity entity;
            entity.x = j;
            entity.y = i;
            entity.element = map[i][j];
            switch (entity.element)
            {
            case WALL:
                entity.red = 255;
                entity.green = 255;
                entity.blue = 255;
                entity.alpha = 150;
                break;
            case COIN:
                entity.red = 100;
                entity.green = 100;
                entity.blue = 100;
                entity.alpha = 200;
                break;
            case POWERUP:
                entity.red = 255;
                entity.green = 0;
                entity.blue = 255;
                entity.alpha = 200;
                break;
            case RED_GHOST:
                entity.red = 255;
                entity.green = 0;
                entity.blue = 0;
                entity.alpha = 200;
                break;
            case PINK_GHOST:
                entity.red = 255;
                entity.green = 105;
                entity.blue = 180;
                entity.alpha = 200;
                break;
            case BLUE_GHOST:
                entity.red = 0;
                entity.green = 0;
                entity.blue = 255;
                entity.alpha = 200;
                break;
            case ORANGE_GHOST:
                entity.red = 255;
                entity.green = 165;
                entity.blue = 0;
                entity.alpha = 200;
                break;
            case TELEPORT:
                entity.red = 0;
                entity.green = 255;
                entity.blue = 0;
                entity.alpha = 200;
                break;
            default:
                entity.red = 0;
                entity.green = 0;
                entity.blue = 0;
                entity.alpha = 0;
                break;
            }
            state.entities.push_back(entity);
        }
    }

    Entity player;
    player.element = 'C';
    player.red = 255;
    player.green = 240;
    player.blue = 0;
    player.alpha = 255;
    player.x = pos_player.second; // colonne
    player.y = pos_player.first;  // ligne
    state.entities.push_back(player);

    return state;
}

void Pacman::handleInput(int key)
{
    int x = pos_player.first;
    int y = pos_player.second;

    switch(key) {
        case 5:
            if (x > 0 && map[x - 1][y] != WALL) movePlayer(x - 1, y);
            break;
        case 6:
            if (x < MAP_HEIGHT - 1 && map[x + 1][y] != WALL) movePlayer(x + 1, y);
            break;
        case 7:
            if (y > 0 && map[x][y - 1] != WALL) movePlayer(x, y - 1);
            break;
        case 8:
            if (y < (int)map[x].size() - 1 && map[x][y + 1] != WALL) movePlayer(x, y + 1);
            break;
    }
}

void Pacman::movePlayer(int new_x, int new_y)
{
    std::pair<int, int> player_tmp = pos_player;
    if (check_bonuses(map[new_x][new_y]) == 0) {
        pos_player = {new_x, new_y};
        map[new_x][new_y] = PLAYER;
    }
    this->map[player_tmp.first][player_tmp.second] = EMPTY;
    this->coin_map[player_tmp.first][player_tmp.second] = EMPTY;
}

void Pacman::loadMap()
{
    std::ifstream file(DEFAULT_MAP);
    std::string line;
    map.clear();
    original_map.clear();
    coin_map.clear();

    while (std::getline(file, line)) {
        if (line.size() > 0) {
            map.push_back(line);
            original_map.push_back(line);
            coin_map.push_back(line);
        }
    }
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
    if (new_pos == RED_GHOST || new_pos == PINK_GHOST || new_pos == BLUE_GHOST || new_pos == ORANGE_GHOST) {
        this->lives -= 1;
        this->pos_player = DEFAULT_PLAYER_POSITION;
        // reset de position des fantomes à faire
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

bool Pacman::win_condition()
{
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < this->map[i].length(); j++) {
            if (this->map[i][j] == COIN || this->map[i][j] == POWERUP)
                return 0;
        }
    }
    return 1;
}

int Pacman::manhattan_distance(std::pair<int, int> a, std::pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

std::pair<int, int> Pacman::move_ghost(std::pair<int, int> pos_ghost, char Ghost)
{
    int distance, tmp = manhattan_distance(pos_ghost, this->pos_player);
    std::pair<int, int> new_pos = pos_ghost;

    if (this->map[pos_ghost.first - 1][pos_ghost.second] != WALL && this->map[pos_ghost.first - 1][pos_ghost.second] != BLUE_GHOST && this->map[pos_ghost.first - 1][pos_ghost.second] != ORANGE_GHOST && this->map[pos_ghost.first - 1][pos_ghost.second] != PINK_GHOST && this->map[pos_ghost.first - 1][pos_ghost.second] != RED_GHOST) {
        if (distance >= manhattan_distance(std::make_pair(pos_ghost.first - 1, pos_ghost.second), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first - 1, pos_ghost.second), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first - 1, pos_ghost.second);
        }
    }
    if (this->map[pos_ghost.first + 1][pos_ghost.second] != WALL && this->map[pos_ghost.first + 1][pos_ghost.second] != BLUE_GHOST && this->map[pos_ghost.first + 1][pos_ghost.second] != ORANGE_GHOST && this->map[pos_ghost.first + 1][pos_ghost.second] != PINK_GHOST && this->map[pos_ghost.first + 1][pos_ghost.second] != RED_GHOST) {
        if (distance >= manhattan_distance(std::make_pair(pos_ghost.first + 1, pos_ghost.second), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first + 1, pos_ghost.second), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first + 1, pos_ghost.second);
        }
    }
    if (this->map[pos_ghost.first][pos_ghost.second - 1] != WALL && this->map[pos_ghost.first][pos_ghost.second - 1] != BLUE_GHOST && this->map[pos_ghost.first][pos_ghost.second - 1] != ORANGE_GHOST && this->map[pos_ghost.first][pos_ghost.second - 1] != PINK_GHOST && this->map[pos_ghost.first][pos_ghost.second - 1] != RED_GHOST) {
        if (distance >= manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second - 1), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second - 1), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first, pos_ghost.second - 1);
        }
    }
    if (this->map[pos_ghost.first][pos_ghost.second + 1] != WALL && this->map[pos_ghost.first][pos_ghost.second + 1] != BLUE_GHOST && this->map[pos_ghost.first][pos_ghost.second + 1] != ORANGE_GHOST && this->map[pos_ghost.first][pos_ghost.second + 1] != PINK_GHOST && this->map[pos_ghost.first][pos_ghost.second + 1] != RED_GHOST) {
        if (distance >= manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second + 1), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second + 1), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first, pos_ghost.second + 1);
        }
    }
    if (tmp == distance)
        return new_pos;
    if (this->map[new_pos.first][new_pos.second] == PLAYER) {
        this->lives -= 1;
        this->pos_player = DEFAULT_PLAYER_POSITION;
        // reset de position des fantômes à faire
    }
    if (this->original_map[pos_ghost.first][pos_ghost.second] == BLUE_GHOST || this->original_map[pos_ghost.first][pos_ghost.second] == ORANGE_GHOST || this->original_map[pos_ghost.first][pos_ghost.second] == PINK_GHOST || this->original_map[pos_ghost.first][pos_ghost.second] == RED_GHOST || this->original_map[pos_ghost.first][pos_ghost.second] == PLAYER)
        this->map[pos_ghost.first][pos_ghost.second] = EMPTY;
    else {
        if (this->coin_map[pos_ghost.first][pos_ghost.second] == COIN || this->coin_map[pos_ghost.first][pos_ghost.second] == POWERUP)
            this->map[pos_ghost.first][pos_ghost.second] = this->original_map[pos_ghost.first][pos_ghost.second];
        else
            this->map[pos_ghost.first][pos_ghost.second] = EMPTY;
    }
    this->map[new_pos.first][new_pos.second] = Ghost;
    return new_pos;
}

extern "C" IGame* create()
{
    return new Pacman();
}
