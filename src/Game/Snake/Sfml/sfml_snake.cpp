/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman_sfml.cpp
*/

#include "sfml_snake.hpp"

SfmlSnake::SfmlSnake(Sfml *sfml) : sfml(sfml) {}

void SfmlSnake::print_map(string *map)
{
    int y = this->sfml->getScreenHeight() / 2;
    int x = this->sfml->getScreenWidth() / 2;

    this->sfml->DrawText2(0, 0, "COUCOU SNAKE");
    // Version sfml
}

SnakeEvent SfmlSnake::pollEvent()
{
    sf::Event event;

    while (sfml->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return SnakeEvent::Quit;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape)
                return SnakeEvent::Quit;
            if (event.key.code == sf::Keyboard::I)
                return SnakeEvent::SwapToNcurses;
            if (event.key.code == sf::Keyboard::O)
                return SnakeEvent::SwapToSdl2;
            if (event.key.code == sf::Keyboard::Up)
                return SnakeEvent::UP;
            if (event.key.code == sf::Keyboard::Down)
                return SnakeEvent::Down;
            if (event.key.code == sf::Keyboard::Left)
                return SnakeEvent::Left;
            if (event.key.code == sf::Keyboard::Right)
                return SnakeEvent::Right;
        }
    }
    return SnakeEvent::None;
}

void SfmlSnake::quit()
{
    this->sfml->stop();
    exit(0);
}
