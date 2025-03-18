#include "pacman.hpp"

Pacman_Game::Pacman_Game()
{
    this->score = 0;
    this->lives = 3;
    this->level = 1;
    this->highscore = 0;
    this->pos_player = std::make_pair(19, 13);
    load_map_from_file("src/Game/PACMAN/map.txt");
}

int Pacman_Game::load_map_from_file(std::string filename)
{
    std::string line;
    std::ifstream file(filename);
    int i = 0;

    if (!file.is_open()) {
        throw std::exception();
        return 84;
    }
    while (std::getline(file, line)) {
        this->map[i].append(line);
        i++;
    }
    file.close();
    return 0;
}

void Pacman_Game::move_player()
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