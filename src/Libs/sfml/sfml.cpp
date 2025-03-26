/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SFML.cpp
*/

#include "sfml.hpp"
#include "../src/Core/ArcadeException.hpp"

void SFMLDisplay::init()
{
    font.loadFromFile("Assets/Font/goofy.ttf");
    window.create(sf::VideoMode(800, 600), "Arcade - sfml");
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
        sf::Color color = {(sf::Uint8)entity.red, (sf::Uint8)entity.green, (sf::Uint8)entity.blue, (sf::Uint8)entity.alpha};
        // switch (entity.type) {
        //     case WALL:  rect.setFillColor(sf::Color::White); break;
        //     case PLAYER: rect.setFillColor(sf::Color::Yellow); break;
        //     case ENEMY: rect.setFillColor(sf::Color::Red); break;
        //     case COIN:  rect.setFillColor(sf::Color::White); break;
        //     case POWERUP: rect.setFillColor(sf::Color::Magenta); break;
        // }
        rect.setFillColor(color);
        window.draw(rect);
    }
    renderText("Menu", 10, 10);
    renderText("1. Pacman", 10, 50);
    renderText("2. Snake", 10, 90);
    window.display();
}

void SFMLDisplay::renderText(const std::string& text, int x, int y)
{
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString(text);
    displayText.setCharacterSize(24);
    displayText.setFillColor(sf::Color::White);
    displayText.setPosition(x, y);
    window.draw(displayText);
}

int SFMLDisplay::getInput()
{
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed)
            return -1;
        if (e.type == sf::Event::KeyPressed) {
            switch (e.key.code) {
                case sf::Keyboard::Q: return -1;
                case sf::Keyboard::I: return 1;
                case sf::Keyboard::O: return 2;
                case sf::Keyboard::P: return 3;
                case sf::Keyboard::Up: return 5;
                case sf::Keyboard::Down: return 6;
                case sf::Keyboard::Left: return 7;
                case sf::Keyboard::Right: return 8;
                case sf::Keyboard::Return: return 10;
            }
        }
    }
    return 0;
}

extern "C" {
    IDisplay* create() { return new SFMLDisplay(); }
}
