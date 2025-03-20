/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_general.cpp
*/

#include "sfml_setup.hpp"

// Event Sfml::pollEvent()
// {
//     sf::Event event;

//     while (window.pollEvent(event)) {
//         if (event.type == sf::Event::Closed)
//             return Event::Quit;
//         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
//             return Event::SwitchToNCurses;
//         if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O)
//             return Event::SwitchToSDL2;
//     }
//     return Event::None;
// }

void Sfml::display()
{
    clearScreen();
    if (gameModule)
        gameModule->draw_game(this);
    refreshScreen();
    sf::sleep(sf::milliseconds(16));
}

void Sfml::DrawText1(int pos_x, int pos_y, string mess)
{
    sf::Text text;
    text.setFont(font);
    text.setString(mess);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos_x, pos_y);
    window.draw(text);
}

void Sfml::DrawText2(int pos_x, int pos_y, string mess)
{
    sf::Text text;
    text.setFont(litle_font);
    text.setString(mess);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setPosition(pos_x, pos_y);
    window.draw(text);
}
