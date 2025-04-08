/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Snake.hpp
*/

#pragma once
#include "../Core/GameInterface.hpp"
#include <vector>
#include <ctime>
#include <chrono>

#define WALL '#'
#define FOOD 'F'
#define SNAKE_HEAD 'X'
#define SNAKE_BODY 'O'
#define DEFAULT_SNAKE_MAP "Assets/Maps/snake_map.txt"
#define MOVE_INTERVAL 200 // ms

class Snake : public IGame {
    private:
        GameState state;
        std::vector<std::pair<int, int>> snakeBody;
        int direction;
        int nextDirection;
        std::pair<int, int> foodPos;
        int score;
        int highScore;
        bool gameOver;
        std::vector<std::string> map;
        std::chrono::time_point<std::chrono::steady_clock> lastMoveTime;

        void generateFood();
        bool checkCollision();
        void loadMap();
        void moveSnake();
        void draw_hud(); // Nouvelle méthode pour mettre à jour le HUD
        void loadHighScore();
        void saveHighScore();

    public:
        Snake();
        GameState update() override;
        void handleInput(int key) override;
        std::string getName() const override { return "Snake"; }
        void reset() override;
};

extern "C" IGame* create();