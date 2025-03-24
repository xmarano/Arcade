/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include <iostream>
#include <filesystem>
#include "Menu.hpp"

Menu::Menu() : current({1, 1}), selectedOption({0, 0}), highScorePacman({"0", "0"}), highScoreSnake({"0", "0"})
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

void Menu::get_highscore()
{
    std::ifstream highscorePacman("stats/pacman_highscore.txt");
    std::ifstream highlevelPacman("stats/pacman_highlevel.txt");

    if (!highscorePacman.is_open() || !highlevelPacman.is_open())
        throw ArcadeException("Error opening highscore or highlevel file for pacman");

    highscorePacman >> highScorePacman.first;
    highlevelPacman >> highScorePacman.second;

    highscorePacman.close();
    highlevelPacman.close();

    // std::ifstream highscoreSnake("stats/snake_highscore.txt");
    // std::ifstream highlevelSnake("stats/snake_highlevel.txt");

    // if (!highscoreSnake.is_open() || !highlevelSnake.is_open())
    //     throw ArcadeException("Error opening highscore or highlevel file for snake");

    // highscoreSnake >> highScoreSnake.first;
    // highlevelSnake >> highScoreSnake.second;

    // highscoreSnake.close();
    // highlevelSnake.close();
}

void Menu::DisplayModules2(IRenderer *renderer)
{
    get_highscore();
    DisplayText(renderer, "USER : __________", 2, 4);
    DisplayText(renderer, "HighScore Pacman : " + highScorePacman.first, 2, 5);
    DisplayText(renderer, "HighLevel Pacman  : " + highScorePacman.second, 2, 6);
    DisplayText(renderer, "HighScore Snake  : " + highScoreSnake.first, 2, 8);
    DisplayText(renderer, "HighLevel Snake  : " + highScoreSnake.second, 2, 9);

    if (current.first == 3 && current.second == 1) {
        DisplayText(renderer, ">> CONFIRM <<", 2, 10);
    } else {
        DisplayText(renderer, "CONFIRM", 2, 10);
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
                set_game(SNAKE_GAME);
                game->draw_game(renderer);
                return selectedOption.second;
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

void Menu::set_game(std::string path_game)
{
    if (this->game != this) {
        delete game;
    }
    this->game = gameLoader.getInstance(path_game);
}
