/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SFML.cpp
*/

#include "../../../include/Core/DisplayInterface.hpp"
#include <SFML/Graphics.hpp>

class SFMLDisplay : public IDisplay
{
    sf::RenderWindow window;
public:
    void init() override {
        window.create(sf::VideoMode(800, 600), "Arcade");
    }

    void close() override {
        window.close();
    }

    void render(const GameState& state) override
    {
        window.clear(sf::Color::Black);

        

        window.display();
    }

    int getInput() override {
        sf::Event e;
        while(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed) return -1;
            if(e.type == sf::Event::KeyPressed) {
                switch(e.key.code) {
                    case sf::Keyboard::Up:    return 0;
                    case sf::Keyboard::Down:  return 1;
                    case sf::Keyboard::Left:  return 2;
                    case sf::Keyboard::Right: return 3;
                }
            }
        }
        return -2;
    }
    std::string getName() const override { return "SFML"; }
};

extern "C" IDisplay* create() { return new SFMLDisplay(); }
