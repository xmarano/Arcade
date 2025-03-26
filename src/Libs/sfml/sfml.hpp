/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** sfml.hpp
*/

#pragma once

#include "../../../include/Core/DisplayInterface.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SFMLDisplay : public IDisplay
{
    sf::RenderWindow window;
    sf::Font font;

    public:
        ~SFMLDisplay() override { close(); }
        void init() override;

        void close() override;
        void render(const GameState& state) override;
        void renderText(const std::string& text, int x, int y);

        int getInput() override;
        std::string getName() const override { return "SFML"; }
};
