/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_general.cpp
*/

#include "sfml_setup.hpp"

int Sfml::display()
{
    int code = 0;

    clearScreen();
    if (gameModule) {
        code = gameModule->draw_game(this);
        if (code > 0)
            return code;
    }
    refreshScreen();
    sf::sleep(sf::milliseconds(16));
    return 0;
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
