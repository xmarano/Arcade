/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** smfl_setup.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../IRenderer.hpp"
#include "../DLLoader.hpp"

class Sfml : public ADisplayModule, public IRenderer
{
    private:
        sf::Font font;
        sf::Font litle_font;
        sf::Font arcade_font;
        sf::Font goofy_font;
        sf::Font arial_font;
        IMenuRenderer* menuRenderer = nullptr;
        IPacmanRenderer* pacmanRenderer = nullptr;
    public:
        Sfml();
        ~Sfml() = default;
        void init() override;
        void stop() override;
        int display() override;
        sf::RenderWindow window;

        IMenuRenderer* getMenuRenderer() override { return menuRenderer; };
        IPacmanRenderer* getPacmanRenderer() override { return pacmanRenderer; };
        void DrawText1(int pos_x, int pos_y, string mess) override;
        void DrawText2(int pos_x, int pos_y, string mess) override;
        void DrawText3(int pos_x, int pos_y, string mess) override;
        void DrawText4(int pos_x, int pos_y, string mess) override;
        void DrawText5(int pos_x, int pos_y, string mess) override;

        void clearScreen() override;
        void refreshScreen() override;
        int getScreenWidth() override;
        int getScreenHeight() override;
};
