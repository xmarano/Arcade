/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake.cpp
*/
#include "Snake.hpp"
#include "../../ArcadeExeption.hpp"

Snake::Snake()
{
    map = load_snake_map(SNAKE_MAP);
    // autres initialisations....
}

string *Snake::load_snake_map(string filename)
{
    string *map = new string[MAP_HEIGHT];
    ifstream file(filename);
    string line;

    if (!file.is_open())
        throw ArcadeException("Can't open file");
    for (int i = 0; getline(file, line); i++) {
        map[i] = line;
    }
    file.close();
    return map;
}

int Snake::draw_game(IRenderer *renderer)
{
    int x = renderer->getScreenWidth();
    int y = renderer->getScreenHeight();
    ISnakeRenderer *snakeRenderer = renderer->getSnakeRenderer();
    int ret = 0;

    while (!is_game_over) { // boucle snake
        renderer->clearScreen();
        snakeRenderer->print_map(map);
        renderer->refreshScreen();
        ret = move_snake(snakeRenderer);
        if (ret == 1) return 1;
        if (ret == 2) return 2;
        if (ret == 3) return 3;
        is_game_over = check_game_over();
    }
    return 0;
}

bool Snake::check_game_over()
{
    return false;
}

int Snake::move_snake(ISnakeRenderer *snakeRenderer)
{
    SnakeEvent ev = snakeRenderer->pollEvent();

    switch (ev) {
        case SnakeEvent::UP:
            // move up
            break;
        case SnakeEvent::Down:
            // move down
            break;
        case SnakeEvent::Left:
            // move left
            break;
        case SnakeEvent::Right:
            // move right
            break;
        default:
            if (ev == SnakeEvent::Quit) snakeRenderer->quit();
            if (ev == SnakeEvent::SwapToNcurses) return 1;
            if (ev == SnakeEvent::SwapToSdl2) return 2;
            if (ev == SnakeEvent::SwapToSfml) return 3;
            break;
    }
    return 0;
}

extern "C" {
    IGameModule *create() {
        return new Snake();
    }
}
