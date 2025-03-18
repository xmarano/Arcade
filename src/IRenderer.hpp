/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

#pragma once

class IMenuRenderer;

class IRenderer {
    public:
        virtual ~IRenderer() = default;
        // Fonctions d'affichage pour Ncurses, SDL2 et [?]
        virtual IMenuRenderer* getMenuRenderer() = 0;
        virtual void DrawText1(int pos_x, int pos_y, std::string mess) = 0; // Font text.ttf
        virtual void DrawText2(int pos_x, int pos_y, std::string mess) = 0; // Font goofy.ttf

        virtual void clearScreen() = 0;
        virtual void refreshScreen() = 0;

        virtual int getScreenWidth() = 0;
        virtual int getScreenHeight() = 0;
};
