/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include <iostream>
#include <filesystem>
#include "Menu.hpp"

Menu::Menu() : selectedOption(0)
{
    pacman = new Pacman();
}

Menu::~Menu()
{
    delete pacman;
}

void Menu::modules(IRenderer *renderer)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();

    IMenuRenderer* menuRenderer = renderer->getMenuRenderer();
    menuRenderer->Draw_Module1();

}

void Menu::DisplayText(IRenderer *renderer, string text, int module, int height)
{
    int screenWidth = renderer->getScreenWidth();
    int screenHeight = renderer->getScreenHeight();
    int y = (screenHeight / 10 * height);
    string error = "!-- ERROR DISPLAY --!";

    if (module == 0) {
        renderer->DrawText1((screenWidth / 2) - (text.length() / 2), y, text);
    } else if (module == 1) {
        renderer->DrawText1(((screenWidth / 3) / 2) - (text.length() / 2), y, text);
    } else if (module == 2) {
        renderer->DrawText1(((screenWidth / 1) / 2) - (text.length() / 2), y, text);
    } else if (module == 3) {
        renderer->DrawText1(((screenWidth / 3) * 2.5) - (text.length() / 2), y, text);
    } else {
        renderer->DrawText1((screenWidth / 2) - (error.length() / 2), y, error);
    }
}

void Menu::DisplayModules1(IRenderer *renderer)
{
    vector<string> moduleGames;
    moduleGames.push_back("Pacman");
    moduleGames.push_back("Snake");

    for (int i = 0; i < moduleGames.size(); i++) {
        DisplayText(renderer, moduleGames[i], 1, i + 4);
    }
}

void Menu::DisplayModules2(IRenderer *renderer)
{
    DisplayText(renderer, "USER", 2, 4);
    DisplayText(renderer, "Score Pacman : 0", 2, 5);
    DisplayText(renderer, "Score Snake  : 0", 2, 5);
}

void Menu::DisplayModules3(IRenderer *renderer)
{
    vector<string> moduleFiles;

    for (const auto &entry : filesystem::directory_iterator("./lib")) {
        if (entry.path().extension() == ".so") {
            string temp_file = entry.path().string();
            int start = temp_file.find("arcade_") + 7;
            int end = temp_file.find(".so");
            temp_file = temp_file.substr(start, end - start);
            moduleFiles.push_back(temp_file);
        }
    }
    for (int i = 0; i < moduleFiles.size(); i++) {
        DisplayText(renderer, moduleFiles[i], 3, i + 4);
    }
}

void Menu::draw_game(IRenderer *renderer)
{
    string title_0 = "Bienvenue sur Arcade !";
    string title_1 = "Jeux disponibles:";
    string title_2 = "Joueur:";
    string title_3 = "Affichage:";

    DisplayText(renderer, title_0, 0, 0);
    DisplayText(renderer, title_1, 1, 2);
    DisplayText(renderer, title_2, 2, 2);
    DisplayText(renderer, title_3, 3, 2);

    vector<int> Selected;

    DisplayModules1(renderer);
    DisplayModules2(renderer);
    DisplayModules3(renderer);

    // Selected.push_back(module1Selected);
    // Selected.push_back(module2Selected);
    // Selected.push_back(module3Selected);
    // à optimiser

    // pacman->draw_game(renderer);
    modules(renderer);
}  
   