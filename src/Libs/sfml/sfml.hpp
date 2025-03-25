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
    public:
        ~SFMLDisplay() override {
            close(); // Fermeture automatique
        }
        void init() override;

        void close() override;
        void render(const GameState& state) override;

        int getInput() override;
        std::string getName() const override { return "SFML"; }
};
