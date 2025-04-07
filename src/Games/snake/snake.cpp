/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Snake.cpp
*/
#include "../../../include/Games/Snake.hpp"
#include <fstream>
#include <algorithm>

Snake::Snake() : highScore(0) {
    std::srand(std::time(nullptr));
    reset();
}

void Snake::reset() {
    snakeBody.clear();
    snakeBody.push_back({8, 2});
    snakeBody.push_back({8, 1});
    snakeBody.push_back({8, 0});
    direction = 8; // Right
    nextDirection = 8;
    score = 0;
    gameOver = false;
    loadMap();
    generateFood();
    lastMoveTime = std::chrono::steady_clock::now();
}

void Snake::loadMap() {
    std::ifstream file(DEFAULT_SNAKE_MAP);
    std::string line;
    map.clear();
    while (std::getline(file, line)) {
        map.push_back(line);
    }
}

void Snake::generateFood() {
    int rows = map.size();
    int cols = map[0].size();
    do {
        foodPos.first = rand() % rows;
        foodPos.second = rand() % cols;
    } while (map[foodPos.first][foodPos.second] == WALL || 
             std::find(snakeBody.begin(), snakeBody.end(), foodPos) != snakeBody.end());
}

bool Snake::checkCollision() {
    auto head = snakeBody.front();
    
    // Mur
    if (map[head.first][head.second] == WALL)
        return true;
    
    // Auto-collision
    for (auto it = snakeBody.begin() + 1; it != snakeBody.end(); ++it)
        if (head == *it)
            return true;
    
    return false;
}

void Snake::moveSnake() {
    auto newHead = snakeBody.front();
    switch (nextDirection) {
        case 5: newHead.first--; break; // Haut
        case 6: newHead.first++; break; // Bas
        case 7: newHead.second--; break; // Gauche
        case 8: newHead.second++; break; // Droite
    }
    
    direction = nextDirection;
    snakeBody.insert(snakeBody.begin(), newHead);
    
    // Vérifier la nourriture
    if (newHead == foodPos) {
        score += 10;
        if (score > highScore) highScore = score;
        generateFood();
    } else {
        snakeBody.pop_back();
    }
}

GameState Snake::update() {
    if (gameOver) return state;
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastMoveTime);
    if (elapsed.count() >= MOVE_INTERVAL) {
        moveSnake();
        lastMoveTime = now;

        if (checkCollision()) {
            gameOver = true;
            return state;
        }
    }

    // Mise à jour de l'affichage
    state.entities.clear();

    // Mur
    for (size_t y = 0; y < map.size(); y++) {
        for (size_t x = 0; x < map[y].size(); x++) {
            if (map[y][x] == WALL) {
                Entity wall;
                wall.x = x;
                wall.y = y;
                wall.element = WALL;
                wall.red = 40;
                wall.green = 40;
                wall.blue = 40;
                wall.alpha = 255;
                state.entities.push_back(wall);
            }
        }
    }

    // Serpent
    for (size_t i = 0; i < snakeBody.size(); i++) {
        Entity part;
        part.x = snakeBody[i].second;
        part.y = snakeBody[i].first;
        part.element = (i == 0) ? SNAKE_HEAD : SNAKE_BODY;
        part.green = (i == 0) ? 255 : 150;
        part.blue = (i == 0) ? 0 : 50;
        part.red = 0;
        part.alpha = 255;
        state.entities.push_back(part);
    }

    // Nourriture
    Entity food;
    food.x = foodPos.second;
    food.y = foodPos.first;
    food.element = FOOD;
    food.red = 255;
    food.green = 40;
    food.blue = 40;
    food.alpha = 255;
    state.entities.push_back(food);

    return state;
}

void Snake::handleInput(int key) {
    const int opposite[] = {0, 0, 0, 0, 0, 6, 5, 8, 7};
    if (key >= 5 && key <= 8 && direction != opposite[key]) {
        nextDirection = key;
    }
}

extern "C" IGame* create() {
    return new Snake();
}
