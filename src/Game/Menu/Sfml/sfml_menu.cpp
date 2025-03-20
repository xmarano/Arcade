/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_menu.cpp
*/

#include "sfml_menu.hpp"

SfmlMenu::SfmlMenu(Sfml *sfml) : sfml(sfml) {}

MenuEvent SfmlMenu::pollEvent()
{
    sf::Event event;

    if (event.type == sf::Event::Closed)
        return MenuEvent::Quit;
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Down)
            return MenuEvent::Down;
        if (event.key.code == sf::Keyboard::Up)
            return MenuEvent::Up;
    }
    return MenuEvent::None;
}

void SfmlMenu::rep_event(MenuEvent event)
{
    if (event == MenuEvent::Down) {
    }
    if (event == MenuEvent::Up) {
    }
    if (event == MenuEvent::Quit) {
        this->sfml->stop();
        exit(0);
    }
}
