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

void Pacman::draw_hud()
{
    // Mise à jour des informations à afficher dans le HUD
    state.score = score;
    state.level = level;
    state.lives = lives;
    state.gameName = "Pacman";
}

void Pacman::loadHighScore()
{
    std::ifstream file("Assets/Stats/pacman_highscore.txt");
    if (file.is_open()) {
        file >> highscore;
        file.close();
    } else {
        highscore = 0;
    }
}

void Pacman::saveHighScore()
{
    std::ofstream file("Assets/Stats/pacman_highscore.txt");
    if (file.is_open()) {
        file << highscore;
        file.close();
    }
}

void Pacman::loadHighLevel()
{
    std::ifstream file("Assets/Stats/pacman_highlevel.txt");
    if (file.is_open()) {
        file >> highLevel;
        file.close();
    } else {
        highLevel = 1;
    }
}

void Pacman::saveHighLevel()
{
    std::ofstream file("Assets/Stats/pacman_highlevel.txt");
    if (file.is_open()) {
        file << highLevel;
        file.close();
    }
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
    phantom_clock = clock();
    player_clock = clock();
    loadHighScore();
    loadHighLevel();
}

GameState Pacman::update() {
    // [...] (déplacements, logique du jeu)
    if (win_condition() == 1) {
        level += 1;
        if (level > highLevel) {
            highLevel = level;
            saveHighLevel();
        }
        this->map = this->original_map;
        reset_positions();
    }
    clock_t time_elasped = clock();
    if (time_elasped - phantom_clock > 150000) {
        pos_red_ghost = move_ghost(pos_red_ghost, RED_GHOST);
        pos_pink_ghost = move_ghost(pos_pink_ghost, PINK_GHOST);
        pos_blue_ghost = move_ghost(pos_blue_ghost, BLUE_GHOST);
        pos_orange_ghost = move_ghost(pos_orange_ghost, ORANGE_GHOST);
        if (pos_red_ghost == std::make_pair(0, 0) || pos_pink_ghost == std::make_pair(0, 0) || pos_blue_ghost == std::make_pair(0, 0) || pos_orange_ghost == std::make_pair(0, 0)) {
            reset_positions();
        }
        phantom_clock = clock();
    }
    if (time_elasped - player_clock > 100000) {
        handleInput(1);
        player_clock = clock();
    }
    if (time_elasped - frozen_clock > 5000000) {
        is_sous_frozen = false;
    }
    
    // Mise à jour du HUD avant de générer les entités
    draw_hud();
    
    // Conversion de la carte en entités génériques
    state.entities.clear();
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            Entity entity;
            entity.x = j;
            entity.y = i;
            entity.element = map[i][j];
            switch (entity.element) {
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
                    if (is_sous_frozen == true) {
                        entity.red = 14;
                        entity.green = 32;
                        entity.blue = 255;
                        entity.alpha = 200;
                    }
                    break;
                case PINK_GHOST:
                    entity.red = 255;
                    entity.green = 105;
                    entity.blue = 180;
                    entity.alpha = 200;
                    if (is_sous_frozen == true) {
                        entity.red = 14;
                        entity.green = 32;
                        entity.blue = 255;
                        entity.alpha = 200;
                    }
                    break;
                case BLUE_GHOST:
                    entity.red = 0;
                    entity.green = 0;
                    entity.blue = 255;
                    entity.alpha = 200;
                    if (is_sous_frozen == true) {
                        entity.red = 14;
                        entity.green = 32;
                        entity.blue = 255;
                        entity.alpha = 200;
                    }
                    break;
                case ORANGE_GHOST:
                    entity.red = 255;
                    entity.green = 165;
                    entity.blue = 0;
                    entity.alpha = 200;
                    if (is_sous_frozen == true) {
                        entity.red = 14;
                        entity.green = 32;
                        entity.blue = 255;
                        entity.alpha = 200;
                    }
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
        if (this->score > highscore) {
            highscore = this->score;
            saveHighScore();
        }
        return 0;
    } else if (new_pos == POWERUP) {
        this->score += (50 * level);
        this->is_sous_frozen = true;
        frozen_clock = clock();
        return 0;
    }
    if (new_pos == RED_GHOST || new_pos == PINK_GHOST || new_pos == BLUE_GHOST || new_pos == ORANGE_GHOST) {
        if (is_sous_frozen == false) {
            this->lives -= 1;
            reset_positions();
            return 1;
        } else {
            if (new_pos == RED_GHOST) {
                this->pos_red_ghost = RED_GHOST_POS;
            } else if (new_pos == PINK_GHOST) {
                this->pos_pink_ghost = PINK_GHOST_POS;
            } else if (new_pos == BLUE_GHOST) {
                this->pos_blue_ghost = BLUE_GHOST_POS;
            } else if (new_pos == ORANGE_GHOST) {
                this->pos_orange_ghost = ORANGE_GHOST_POS;
            }
            this->score += (200 * level);
            return 0;
        }
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

bool Pacman::is_valid_position(std::pair<int, int> pos)
{
    if (pos.first < 0 || pos.first >= MAP_HEIGHT || pos.second < 0 || pos.second >= this->map[pos.first].length())
        return false;
    if (this->map[pos.first][pos.second] == COIN || this->map[pos.first][pos.second] == POWERUP || this->map[pos.first][pos.second] == EMPTY || this->map[pos.first][pos.second] == PLAYER)
        return true;
    return false;
}

void Pacman::reset_positions()
{
    this->pos_player = DEFAULT_PLAYER_POSITION;
    this->map[pos_red_ghost.first][pos_red_ghost.second] = this->coin_map[pos_red_ghost.first][pos_red_ghost.second];
    this->map[pos_pink_ghost.first][pos_pink_ghost.second] = this->coin_map[pos_pink_ghost.first][pos_pink_ghost.second];
    this->map[pos_blue_ghost.first][pos_blue_ghost.second] = this->coin_map[pos_blue_ghost.first][pos_blue_ghost.second];
    this->map[pos_orange_ghost.first][pos_orange_ghost.second] = this->coin_map[pos_orange_ghost.first][pos_orange_ghost.second];
    this->pos_red_ghost = RED_GHOST_POS;
    this->pos_pink_ghost = PINK_GHOST_POS;
    this->pos_blue_ghost = BLUE_GHOST_POS;
    this->pos_orange_ghost = ORANGE_GHOST_POS;
}

std::pair<int, int> Pacman::random_move(std::pair<int, int> pos)
{
    std::vector<std::pair<int, int>> moves;
    if (is_valid_position(std::make_pair(pos.first - 1, pos.second)) == true)
        moves.push_back(std::make_pair(pos.first - 1, pos.second));
    if (is_valid_position(std::make_pair(pos.first + 1, pos.second)) == true)
        moves.push_back(std::make_pair(pos.first + 1, pos.second));
    if (is_valid_position(std::make_pair(pos.first, pos.second - 1)) == true)
        moves.push_back(std::make_pair(pos.first, pos.second - 1));
    if (is_valid_position(std::make_pair(pos.first, pos.second + 1)) == true)
        moves.push_back(std::make_pair(pos.first, pos.second + 1));
    if (moves.empty())
        return pos;
    return moves[rand() % moves.size()];
}

std::pair<int, int> Pacman::move_ghost(std::pair<int, int> pos_ghost, char Ghost)
{
    std::pair<int, int> new_pos = pos_ghost;

    if (is_sous_frozen == false)
        new_pos = chase_movement(pos_ghost);
    else
        new_pos = fear_movement(pos_ghost);
    if (this->map[new_pos.first][new_pos.second] == PLAYER) {
        this->map[pos_ghost.first][pos_ghost.second] = this->coin_map[pos_ghost.first][pos_ghost.second];
        if (is_sous_frozen == false) {
            this->lives -= 1;
            return std::make_pair(0, 0);
        } else {
            if (Ghost == RED_GHOST) {
                this->pos_red_ghost = RED_GHOST_POS;
                this->score += (200 * level);
                return this->pos_red_ghost;
            } else if (Ghost == PINK_GHOST) {
                this->pos_pink_ghost = PINK_GHOST_POS;
                this->score += (200 * level);
                return this->pos_pink_ghost;
            } else if (Ghost == BLUE_GHOST) {
                this->pos_blue_ghost = BLUE_GHOST_POS;
                this->score += (200 * level);
                return this->pos_blue_ghost;
            } else if (Ghost == ORANGE_GHOST) {
                this->pos_orange_ghost = ORANGE_GHOST_POS;
                this->score += (200 * level);
                return this->pos_orange_ghost;
            }
        }
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

std::pair<int, int> Pacman::chase_movement(std::pair<int, int> pos_ghost)
{
    int tmp = manhattan_distance(pos_ghost, this->pos_player);
    int distance = manhattan_distance(pos_ghost, this->pos_player);
    std::pair<int, int> new_pos = pos_ghost;

    if (is_valid_position(std::make_pair(pos_ghost.first - 1, pos_ghost.second)) == true) {
        if (distance > manhattan_distance(std::make_pair(pos_ghost.first - 1, pos_ghost.second), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first - 1, pos_ghost.second), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first - 1, pos_ghost.second);
        }
    }
    if (is_valid_position(std::make_pair(pos_ghost.first + 1, pos_ghost.second)) == true) {
        if (distance > manhattan_distance(std::make_pair(pos_ghost.first + 1, pos_ghost.second), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first + 1, pos_ghost.second), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first + 1, pos_ghost.second);
        }
    }
    if (is_valid_position(std::make_pair(pos_ghost.first, pos_ghost.second - 1)) == true) {
        if (distance > manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second - 1), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second - 1), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first, pos_ghost.second - 1);
        }
    }
    if (is_valid_position(std::make_pair(pos_ghost.first, pos_ghost.second + 1)) == true) {
        if (distance > manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second + 1), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second + 1), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first, pos_ghost.second + 1);
        }
    }
    if (tmp == distance)
        new_pos = random_move(pos_ghost);
    return new_pos;
}

std::pair<int, int> Pacman::fear_movement(std::pair<int, int> pos_ghost)
{
    int tmp = manhattan_distance(pos_ghost, this->pos_player);
    int distance = manhattan_distance(pos_ghost, this->pos_player);
    std::pair<int, int> new_pos = pos_ghost;

    if (is_valid_position(std::make_pair(pos_ghost.first - 1, pos_ghost.second)) == true) {
        if (distance < manhattan_distance(std::make_pair(pos_ghost.first - 1, pos_ghost.second), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first - 1, pos_ghost.second), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first - 1, pos_ghost.second);
        }
    }
    if (is_valid_position(std::make_pair(pos_ghost.first + 1, pos_ghost.second)) == true) {
        if (distance < manhattan_distance(std::make_pair(pos_ghost.first + 1, pos_ghost.second), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first + 1, pos_ghost.second), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first + 1, pos_ghost.second);
        }
    }
    if (is_valid_position(std::make_pair(pos_ghost.first, pos_ghost.second - 1)) == true) {
        if (distance < manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second - 1), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second - 1), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first, pos_ghost.second - 1);
        }
    }
    if (is_valid_position(std::make_pair(pos_ghost.first, pos_ghost.second + 1)) == true) {
        if (distance < manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second + 1), this->pos_player)) {
            distance = manhattan_distance(std::make_pair(pos_ghost.first, pos_ghost.second + 1), this->pos_player);
            new_pos = std::make_pair(pos_ghost.first, pos_ghost.second + 1);
        }
    }
    if (tmp == distance)
        new_pos = random_move(pos_ghost);
    return new_pos;
}
