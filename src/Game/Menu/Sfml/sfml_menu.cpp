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

    while (sfml->window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return MenuEvent::Quit;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::I)
                return MenuEvent::SwapToNcurses;
            if (event.key.code == sf::Keyboard::O)
                return MenuEvent::SwapToSdl2;
            if (event.key.code == sf::Keyboard::K)
                return MenuEvent::PlayPacman;
        }
    }
    return MenuEvent::None;
}

void SfmlMenu::rep_event(MenuEvent event)
{
    if (event == MenuEvent::Quit) {
        this->sfml->stop();
        exit(0);
    }
}
