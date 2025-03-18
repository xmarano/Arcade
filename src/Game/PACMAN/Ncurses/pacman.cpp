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
        this->map[i]->append(line);
        i++;
    }
    file.close();
    return 0;
}