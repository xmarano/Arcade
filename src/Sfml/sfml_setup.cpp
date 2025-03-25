/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_setup.cpp
*/

#include "sfml_setup.hpp"
#include "../Menu/Sfml/sfml_menu.hpp"
#include "../Game/Pacman/Sdl2/sdl2_pacman.hpp"
#include "../Game/Pacman/Sfml/sfml_pacman.hpp"
#include "../Game/Snake/Sfml/sfml_snake.hpp"

Sfml::Sfml() : ADisplayModule("SDL2"), window()
{
    menuRenderer = new SfmlMenu(this);
    pacmanRenderer = new SfmlPacman(this);
    snakeRenderer = new SfmlSnake(this);
}

void Sfml::init()
{
    window.create(sf::VideoMode(1280, 720), "Arcade - SFML");
    font.loadFromFile("Assets/Font/text.ttf");
    litle_font.loadFromFile("Assets/Font/little.ttf");
    arcade_font.loadFromFile("Assets/Font/arcade.ttf");
    goofy_font.loadFromFile("Assets/Font/goofy.ttf");
    arial_font.loadFromFile("Assets/Font/arial.ttf");
}

void Sfml::stop()
{
    window.close();
}

void Sfml::clearScreen()
{
    window.clear();
}

void Sfml::refreshScreen()
{
    window.display();
}

extern "C" {
    IDisplayModule *create()
    {
        return new Sfml();
    }
}

int Sfml::getScreenWidth()
{
    return window.getSize().x;
}

int Sfml::getScreenHeight()
{
    return window.getSize().y;
}
