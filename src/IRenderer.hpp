/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IRenderer.hpp
*/

#pragma once

class IRenderer {
    public:
        virtual ~IRenderer() = default;

        // Fonctions d'affichage pour Ncurses, SDL2 et [?]

        virtual void DrawText(int pos_x, int pos_y, std::string mess) = 0; // Affichage du titre du menu
            // virtual void Draw_Module1() = 0; // Module selection du jeu
            // virtual void Draw_Module2() = 0; // Module du profil du joueur
            // virtual void Draw_Module3() = 0; // Module de selection de la lib graphique

        virtual void clearScreen() = 0;
        virtual void refreshScreen() = 0;

        virtual int getScreenWidth() = 0;
        virtual int getScreenHeight() = 0;
};
