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

        virtual void DrawTitleMenu() = 0; // Affichage du titre du menu
            virtual void Draw_Module1() = 0; // Module selection du jeu
            virtual void Draw_Module2() = 0; // Module du profil du joueur
            virtual void Draw_Module3() = 0; // Module de selection de la lib graphique

        virtual void clearScreen() = 0;
        virtual void refreshScreen() = 0;
        virtual void getScreenWidth() = 0;
        virtual void getScreenHeight() = 0;
};
