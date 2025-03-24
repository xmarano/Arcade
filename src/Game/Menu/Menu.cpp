/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include <iostream>
#include <filesystem>
#include "Menu.hpp"

Menu::Menu() : current({1, 1}), selectedOption({0, 0})
{
}

Menu::~Menu()
{
    delete game;
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
        if (current.first == 1 && current.second == i + 1) {
            DisplayText(renderer, "> " + moduleGames[i] + " <", 1, i + 4);
        } else {
            DisplayText(renderer, moduleGames[i], 1, i + 4);
        }
    }
}

vector<string> Menu::get_highscore()
{
    vector<string> highScore(4);
    // Pacman
    ifstream highscorePacman("stats/pacman_highscore.txt");
    ifstream highlevelPacman("stats/pacman_highlevel.txt");

    if (!highscorePacman.is_open() || !highlevelPacman.is_open())
        throw ArcadeException("Error opening highscore or highlevel file for pacman");

    highscorePacman >> highScore[0];
    highlevelPacman >> highScore[1];

    highscorePacman.close();
    highlevelPacman.close();

    // Snake
    ifstream highscoreSnake("stats/snake_highscore.txt");
    ifstream highlevelSnake("stats/snake_highlevel.txt");

    if (!highscoreSnake.is_open() || !highlevelSnake.is_open())
        throw ArcadeException("Error opening highscore or highlevel file for snake");

    highscoreSnake >> highScore[2];
    highlevelSnake >> highScore[3];

    highscoreSnake.close();
    highlevelSnake.close();
    return highScore;
}

void Menu::DisplayModules2(IRenderer *renderer)
{
    vector<string> highScore = get_highscore();
    DisplayText(renderer, "USER : __________", 2, 4);
    DisplayText(renderer, "HighScore Pacman : " + highScore[0], 2, 6);
    DisplayText(renderer, "HighLevel Pacman  : " + highScore[1], 2, 7);
    DisplayText(renderer, "HighScore Snake  : " + highScore[2], 2, 9);
    DisplayText(renderer, "HighLevel Snake  : " + highScore[3], 2, 10);

    if (current.first == 3 && current.second == 1) {
        DisplayText(renderer, ">> CONFIRM <<", 2, 12);
    } else {
        DisplayText(renderer, "CONFIRM", 2, 12);
    }
}

void Menu::DisplayModules3(IRenderer *renderer)
{
    vector<string> moduleFiles;

    // for (const auto &entry : filesystem::directory_iterator("./lib")) {
    //     if (entry.path().extension() == ".so") {
    //         string temp_file = entry.path().string();
    //         int start = temp_file.find("arcade_") + 7;
    //         int end = temp_file.find(".so");
    //         temp_file = temp_file.substr(start, end - start);
    //         moduleFiles.push_back(temp_file);
    //     }
    // }
    moduleFiles.push_back("Ncurses");
    moduleFiles.push_back("Sdl2");
    moduleFiles.push_back("Sfml");
    for (int i = 0; i < moduleFiles.size(); i++) {
        if (current.first == 2 && current.second == i + 1) {
            DisplayText(renderer, "> " + moduleFiles[i] + " <", 3, i + 4);
        } else {
            DisplayText(renderer, moduleFiles[i], 3, i + 4);
        }
    }
}

int Menu::Actions(IRenderer *renderer, MenuEvent ev)
{
    if (ev == MenuEvent::Up) {
        if (current.second > 1) {
            current.second--;
        }
    }
    if (ev == MenuEvent::Down) {
        if (current.first == 1) {
            if (current.second < 2) {
                current.second++;
            }
        }
        if (current.first == 2) {
            if (current.second < 3) {
                current.second++;
            }
        }
    }
    if (ev == MenuEvent::Enter) {
        if (current.first == 1) {
            selectedOption.first = current.second;
            current.first = 2;
            current.second = 1;
        } else if (current.first == 2) {
            selectedOption.second = current.second;
            current.first = 3;
            current.second = 1;
        } else if (current.first == 3) {
            // pacman
            if (selectedOption.first == 1 && selectedOption.second == 1) {
                return CODE_NC_PACMAN;
            } else if (selectedOption.first == 1 && selectedOption.second == 2) {
                return CODE_SDL2_PACMAN;
            } else if (selectedOption.first == 1 && selectedOption.second == 3) {
                return CODE_SFML_PACMAN;
            }
            // snake
            if (selectedOption.first == 2) {
                // ok
            }
        }
    }
    if (ev == MenuEvent::Back) {
        if (current.first == 2) {
            current.first = 1;
            if (current.second == 3) {
                current.second = 2;
            }
        } else if (current.first == 3) {
            current.first = 2;
        }
    }
    return 0;
}

int Menu::draw_game(IRenderer *renderer)
{
    string title_0 = "Bienvenue sur Arcade !";
    string title_1 = "Jeux disponibles:";
    string title_2 = "Joueur:";
    string title_3 = "Affichage:";
    IMenuRenderer *menuRenderer = renderer->getMenuRenderer();

    DisplayText(renderer, title_0, 0, 0);
    DisplayText(renderer, title_1, 1, 2);
    DisplayText(renderer, title_2, 2, 2);
    DisplayText(renderer, title_3, 3, 2);

    DisplayModules1(renderer);
    DisplayModules2(renderer);
    DisplayModules3(renderer);

    MenuEvent ev = menuRenderer->pollEvent();
    menuRenderer->rep_event(ev);

    int ret = Actions(renderer, ev);

    if (ret == CODE_NC_PACMAN) return CODE_NC_PACMAN;
    if (ret == CODE_SDL2_PACMAN) return CODE_SDL2_PACMAN;
    if (ret == CODE_SFML_PACMAN) return CODE_SFML_PACMAN;
    return 0;
}
