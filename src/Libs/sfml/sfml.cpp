/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SFML.cpp
*/

#include "sfml.hpp"

void SFMLDisplay::init()
{
    window.create(sf::VideoMode(800, 600), "Arcade");
}

void SFMLDisplay::close()
{
    window.close();
}

void SFMLDisplay::render(const GameState &state)
{
    window.clear();
    for (const auto& entity : state.entities) {
        sf::RectangleShape rect(sf::Vector2f(20, 20));
        rect.setPosition(entity.x * 20, entity.y * 20);
        // switch (entity.type) {
        //     case WALL:  rect.setFillColor(sf::Color::White); break;
        //     case PLAYER: rect.setFillColor(sf::Color::Yellow); break;
        //     case ENEMY: rect.setFillColor(sf::Color::Red); break;
        //     case COIN:  rect.setFillColor(sf::Color::White); break;
        //     case POWERUP: rect.setFillColor(sf::Color::Magenta); break;
        // }
        rect.setFillColor(sf::Color::Magenta); break;
        window.draw(rect);
    }
    window.display();
}

int SFMLDisplay::getInput()
{

    cout << "Ncurszzees input" << endl;
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            return -1;
        if (e.type == sf::Event::KeyPressed) {
            switch (e.key.code) {
                case sf::Keyboard::I: return 1;
                case sf::Keyboard::O: return 2;
            }
        }
    }
    return 0;
}

extern "C" {
    IDisplay* create() { return new SFMLDisplay(); }
}
