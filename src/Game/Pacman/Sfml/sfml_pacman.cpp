/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** pacman_sfml.cpp
*/

#include "sfml_pacman.hpp"

SfmlPacman::SfmlPacman(Sfml *sfml) : sfml(sfml) {}

void SfmlPacman::print_map(std::string *map, int score, int lives, int level, int highscore)
{
    (void)map;
    (void)score;
    (void)lives;
    (void)level;
    (void)highscore;
    this->sfml->DrawText1(0, 0, "COUCOU SFML");
}

PacmanEvent SfmlPacman::pollEvent()
{
    sf::Event event;

    while (sfml->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return PacmanEvent::Quit;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape)
                return PacmanEvent::Quit;
            if (event.key.code == sf::Keyboard::I)
                return PacmanEvent::SwapToNcurses;
            if (event.key.code == sf::Keyboard::O)
                return PacmanEvent::SwapToSdl2;
            if (event.key.code == sf::Keyboard::Up)
                return PacmanEvent::UP;
            if (event.key.code == sf::Keyboard::Down)
                return PacmanEvent::Down;
            if (event.key.code == sf::Keyboard::Left)
                return PacmanEvent::Left;
            if (event.key.code == sf::Keyboard::Right)
                return PacmanEvent::Right;
        }
    }
    return PacmanEvent::None;
}

void SfmlPacman::quit()
{
    this->sfml->stop();
    exit(0);
}
