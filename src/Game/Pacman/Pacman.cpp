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
        renderer->clearScreen();
        pacmanRenderer->print_map(this->map, this->score, this->lives, this->level, this->highscore);
        renderer->refreshScreen();
        this->pos_blue_ghost = move_ghost(this->pos_blue_ghost, BLUE_GHOST);
        this->pos_orange_ghost = move_ghost(this->pos_orange_ghost, ORANGE_GHOST);
        this->pos_pink_ghost = move_ghost(this->pos_pink_ghost, PINK_GHOST);
        this->pos_red_ghost = move_ghost(this->pos_red_ghost, RED_GHOST);
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
    this->pos_blue_ghost = BLUE_GHOST_POS;
    this->pos_orange_ghost = ORANGE_GHOST_POS;
    this->pos_pink_ghost = PINK_GHOST_POS;
    this->pos_red_ghost = RED_GHOST_POS;
    this->pos_player = DEFAULT_PLAYER_POSITION;
    this->is_sous_frozen = false;
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
                this->coin_map[x][y] = EMPTY;
            }
            break;
        case PacmanEvent::Down:
            if (this->map[x + 1][y] != WALL) {
                if (check_bonuses(this->map[x + 1][y]) == 0) {
                    this->map[x + 1][y] = PLAYER;
                    this->pos_player.first = x + 1;
                }
                this->map[x][y] = EMPTY;
                this->coin_map[x][y] = EMPTY;
            }
            break;
        case PacmanEvent::Left:
            if (this->map[x][y - 1] != WALL) {
                if (check_bonuses(this->map[x][y - 1]) == 0) {
                    this->map[x][y - 1] = PLAYER;
                    this->pos_player.second = y - 1;
                }
                this->map[x][y] = EMPTY;
                this->coin_map[x][y] = EMPTY;
            }
            break;
        case PacmanEvent::Right:
            if (this->map[x][y + 1] != WALL) {
                if (check_bonuses(this->map[x][y + 1]) == 0) {
                    this->map[x][y + 1] = PLAYER;
                    this->pos_player.second = y + 1;
                }
                this->map[x][y] = EMPTY;
                this->coin_map[x][y] = EMPTY;
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
    this->original_map = new std::string[MAP_HEIGHT];
    this->coin_map = new std::string[MAP_HEIGHT];

    while (std::getline(file, line)) {
        if (i < MAP_HEIGHT) {
            this->map[i].assign(line);
            this->original_map[i].assign(line);
            this->coin_map[i].assign(line);
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
    if (new_pos == RED_GHOST || new_pos == PINK_GHOST || new_pos == BLUE_GHOST || new_pos == ORANGE_GHOST) {
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
            if (this->map[i][j] == COIN || this->map[i][j] == POWERUP)
                return 0;
        }
    }
    return 1;
}

void Pacman::pacmanHighStats(string stat)
{
    ifstream infile("Assets/Stats/pacman_high" + stat + ".txt");
    int old_highscore = 0;

    if (infile.is_open()) {
        infile >> old_highscore;
        infile.close();
    }
    int new_score = 999;
    if (stat == "score") {
        new_score = this->highscore;
    } else if (stat == "level") {
        new_score = this->level;
    }

    if (new_score > old_highscore) {
        ofstream outfile("Assets/Stats/pacman_high" + stat + ".txt");
        if (outfile.is_open()) {
            outfile << new_score;
            outfile.close();
        }
    }
}

void Pacman::end_of_level()
{
    if (this->lives <= 0) {
        this->lives = 3;
        this->highscore = this->score;
        this->score = 0;
        this->level = 1;
        pacmanHighStats("score");
        pacmanHighStats("level");
    } else {
        this->level += 1;
    }
    this->map = this->original_map;
    this->pos_blue_ghost = BLUE_GHOST_POS;
    this->pos_orange_ghost = ORANGE_GHOST_POS;
    this->pos_pink_ghost = PINK_GHOST_POS;
    this->pos_red_ghost = RED_GHOST_POS;
    this->pos_player = DEFAULT_PLAYER_POSITION;
    this->is_sous_frozen = false;
}

extern "C" {
    IGameModule *create() {
        return new Pacman();
    }
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