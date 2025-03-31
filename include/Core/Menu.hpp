/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.hpp
*/

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "DLLoader.hpp"
#include "DisplayInterface.hpp"
using namespace std;
    #define CODE_NC_PACMAN 4
    #define CODE_SDL2_PACMAN 5
    #define CODE_SFML_PACMAN 6
    #define CODE_NC_SNAKE 7
    #define CODE_SDL2_SNAKE 8
    #define CODE_SFML_SNAKE 9

enum class MenuEvent {
    None,
    Quit,
    Up,
    Down,
    Enter,
    Back,
    PlayPacman,
    PlaySnake,
};

class Menu {
    private:
        pair<int, int> current;
        pair<int, int> selectedOption;
        bool isUsernameSet;
        IDisplay *renderer;
    public:
        Menu();
        ~Menu();
        int draw_menu(IDisplay *renderer); // Ajouter le paramètre IDisplay*
        void DisplayText(IMenuRenderer *menuRenderer, string text, int module, int height);
        void DisplayModules1(IMenuRenderer *menuRenderer);
        void DisplayModules2(IMenuRenderer *menuRenderer);
        void DisplayModules3(IMenuRenderer *menuRenderer);
        vector<string> get_stats();
        int Actions(MenuEvent ev); // Corriger le paramètre
        int getScreenWidth();
        int getScreenHeight();
};

class IMenuRenderer {
    public:
        virtual ~IMenuRenderer() = default;
        virtual MenuEvent pollEvent() = 0;

        virtual void DrawText1(int pos_x, int pos_y, string text) = 0;
        virtual void clearScreen() = 0;
        virtual void displayy() = 0;
};
