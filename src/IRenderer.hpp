/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

#pragma once
#include <string>

class IRenderer {
    public:
        virtual ~IRenderer() = default;

        // Fonctions d'affichage pour Ncurses, SDL2 et [?]

        //! Methode virtuelle du menu principal

        virtual void DrawTitleMenu(const std::string &text) = 0;
        virtual void draw_sprite(const std::string &spritePath) = 0;
        virtual void draw_box(int width, int height) = 0;

        virtual void clearScreen() = 0;
        virtual void refreshScreen() = 0;
        virtual void getScreenWidth() = 0;
        virtual void getScreenHeight() = 0;
};
