/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_menu.cpp
*/

#include "sfml_menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../../Libs/sfml/sfml.hpp"

SfmlMenu::SfmlMenu(SFMLDisplay *disp) : display(disp) {}

MenuEvent SfmlMenu::pollEvent()
{
    sf::Event event;

    while (display->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return MenuEvent::Quit;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::Escape)
                return MenuEvent::Quit;
            if (event.key.code == sf::Keyboard::Down)
                return MenuEvent::Down;
            if (event.key.code == sf::Keyboard::Up)
                return MenuEvent::Up;
            if (event.key.code == sf::Keyboard::Return)
                return MenuEvent::Enter;
            if (event.key.code == sf::Keyboard::BackSpace)
                return MenuEvent::Back;
            if (event.key.code == sf::Keyboard::H)
                return MenuEvent::PlayPacman;
        }
    }
    return MenuEvent::None;
}

void SfmlMenu::DrawText1(int pos_x, int pos_y, string text)
{
    sf::Text displayText;

    displayText.setFont(display->font);
    displayText.setString(text);
    displayText.setCharacterSize(24);
    displayText.setFillColor(sf::Color::White);
    displayText.setPosition(pos_x, pos_y);
    display->window.draw(displayText);
}

void SfmlMenu::clearScreen()
{
    display->window.clear();
}

void SfmlMenu::displayy()
{
    display->window.display();
}
