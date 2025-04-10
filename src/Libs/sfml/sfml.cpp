/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SFML.cpp
*/

#include "sfml.hpp"
#include "../../../src/Core/Menu/sfml/sfml_menu.hpp"

SFMLDisplay::SFMLDisplay() : menuRenderer(nullptr) {}

SFMLDisplay::~SFMLDisplay()
{
    if (menuRenderer) {
        delete menuRenderer;
    }
    close();
}

IMenuRenderer* SFMLDisplay::getMenuRenderer()
{
    if (!menuRenderer) {
        menuRenderer = new SfmlMenu(this);
    }
    return static_cast<IMenuRenderer*>(menuRenderer);
}

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
    
    // Affichage du score et du niveau
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setString("Score: " + std::to_string(state.score));
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(500, 20);
    window.draw(scoreText);
    
    sf::Text levelText;
    levelText.setFont(font);
    levelText.setString("Level: " + std::to_string(state.level));
    levelText.setCharacterSize(24);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(500, 50);
    window.draw(levelText);
    
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
                default: return 0; // a verifier si ça pose problème
            }
        }
    }
    return 0;
}

int SFMLDisplay::getScreenWidth()
{
    return window.getSize().x;
}

int SFMLDisplay::getScreenHeight()
{
    return window.getSize().y;
}

extern "C" {
    IDisplay* create() { return new SFMLDisplay(); }
}
