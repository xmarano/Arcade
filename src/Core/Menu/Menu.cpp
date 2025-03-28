/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include <iostream>
#include <filesystem>
#include "../../../include/Core/Menu.hpp"
#include <ncurses.h>

Menu::Menu() : current({1, 1}), selectedOption({0, 0}), isUsernameSet(false)
{
}

Menu::~Menu()
{
}

int Menu::getScreenWidth()
{
    if (!renderer) return 0;
    return renderer->getScreenWidth();
}

int Menu::getScreenHeight()
{
    if (!renderer) return 0;
    return renderer->getScreenHeight();
}

void Menu::DisplayText(IMenuRenderer *menuRenderer, string text, int module, int height)
{
    int screenWidth = getScreenWidth();
    int screenHeight = getScreenHeight();
    int y = (screenHeight / 10 * height);

    string error = "!-- ERROR DISPLAY --!";
    if (module == 0) {
        menuRenderer->DrawText1((screenWidth / 2) - (text.length() / 2), y, text);
    } else if (module == 1) {
        menuRenderer->DrawText1(((screenWidth / 3) / 2) - (text.length() / 2), y, text);
    } else if (module == 2) {
        menuRenderer->DrawText1(((screenWidth / 1) / 2) - (text.length() / 2), y, text);
    } else if (module == 3) {
        menuRenderer->DrawText1(((screenWidth / 3) * 2.5) - (text.length() / 2), y, text);
    } else {
        menuRenderer->DrawText1((screenWidth / 2) - (error.length() / 2), y, error);
    }
}

void Menu::DisplayModules1(IMenuRenderer *menuRenderer)
{
    vector<string> moduleGames;
    moduleGames.push_back("Pacman");
    moduleGames.push_back("Snake");

    for (int i = 0; i < moduleGames.size(); i++) {
        if (current.first == 1 && current.second == i + 1) {
            DisplayText(menuRenderer, "> " + moduleGames[i] + " <", 1, i + 4);
        } else {
            DisplayText(menuRenderer, moduleGames[i], 1, i + 4);
        }
    }
}

vector<string> Menu::get_stats()
{
    vector<string> highScore(4);
    // Username
    ifstream usernameFile("Assets/Stats/username.txt");
    if (!usernameFile.is_open())
        throw ArcadeException("Error opening username file");

    usernameFile >> highScore[0];
    if (highScore[0] == "")
        highScore[0] = "__________";
    else
        isUsernameSet = true;

    usernameFile.close();

    // Pacman
    ifstream highscorePacman("Assets/Stats/pacman_highscore.txt");
    ifstream highlevelPacman("Assets/Stats/pacman_highlevel.txt");

    if (!highscorePacman.is_open() || !highlevelPacman.is_open())
        throw ArcadeException("Error opening highscore or highlevel file for pacman");

    highscorePacman >> highScore[1];
    highlevelPacman >> highScore[2];

    highscorePacman.close();
    highlevelPacman.close();

    // Snake
    ifstream highscoreSnake("Assets/Stats/snake_highscore.txt");

    if (!highscoreSnake.is_open())
        throw ArcadeException("Error opening highscore file for snake");

    highscoreSnake >> highScore[3];

    highscoreSnake.close();
    return highScore;
}

void Menu::DisplayModules2(IMenuRenderer *menuRenderer)
{
    vector<string> highScore = get_stats();
    if (current.first != 3) {
        DisplayText(menuRenderer, "User : " + highScore[0], 2, 4);
    }
    DisplayText(menuRenderer, "HighScore Pacman : " + highScore[1], 2, 5);
    DisplayText(menuRenderer, "HighLevel Pacman  : " + highScore[2], 2, 6);
    DisplayText(menuRenderer, "HighScore Snake  : " + highScore[3], 2, 7);

    DisplayText(menuRenderer, "+---------------+", 2, 8);
    if (current.first == 4 && current.second == 1) {
        DisplayText(menuRenderer, "| >> CONFIRM << |", 2, 9);
    } else {
        DisplayText(menuRenderer, "|    CONFIRM    |", 2, 9);
    }
    DisplayText(menuRenderer, "+---------------+", 2, 10);
}

void Menu::DisplayModules3(IMenuRenderer *menuRenderer)
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
            DisplayText(menuRenderer, "> " + moduleFiles[i] + " <", 3, i + 4);
        } else {
            DisplayText(menuRenderer, moduleFiles[i], 3, i + 4);
        }
    }
}

int Menu::Actions(MenuEvent ev)
{
    if (ev == MenuEvent::Quit) {
        return -1;
    }
    if (ev == MenuEvent::PlayPacman) {
        return CODE_NC_PACMAN;
    }
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
            string username;
            ifstream userFile("Assets/Stats/username.txt");
            userFile >> username;
            userFile.close();
            if (username == "") {
                current.first = 3;
            } else {
                current.first = 4;
            }
            current.second = 1;
        } else if (current.first == 3) {
            if (!isUsernameSet) {
                // string username;
                // char ch;
                // while ((ch = getch()) != '\n') {
                    // username += ch;
                    // DisplayText("User : " + username, 2, 4);
                // }
                // ofstream userFile("Assets/Stats/username.txt");
                // userFile << username;
                // userFile.close();
            }
            current.first = 4;
        } else if (current.first == 4) {
            // pacman
            if (selectedOption.first == 1 && selectedOption.second == 1) {
                return CODE_NC_PACMAN;
            } else if (selectedOption.first == 1 && selectedOption.second == 2) {
                return CODE_SDL2_PACMAN;
            } else if (selectedOption.first == 1 && selectedOption.second == 3) {
                return CODE_SFML_PACMAN;
            }
            // snake
            if (selectedOption.first == 2 && selectedOption.second == 1) {
                return CODE_NC_SNAKE;
            } else if (selectedOption.first == 2 && selectedOption.second == 2) {
                return CODE_SDL2_SNAKE;
            } else if (selectedOption.first == 2 && selectedOption.second == 3) {
                return CODE_SFML_SNAKE;
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

int Menu::draw_menu(IDisplay *renderer)
{
    this->renderer = renderer;
    string title_0 = "Bienvenue sur Arcade !";
    string title_1 = "Jeux disponibles:";
    string title_2 = "Joueur:";
    string title_3 = "Affichage:";
    IMenuRenderer *menuRenderer = renderer->getMenuRenderer();

    menuRenderer->clearScreen();

    DisplayText(menuRenderer, title_0, 0, 0);
    DisplayText(menuRenderer, title_1, 1, 2);
    DisplayText(menuRenderer, title_2, 2, 2);
    DisplayText(menuRenderer, title_3, 3, 2);

    DisplayModules1(menuRenderer);
    DisplayModules2(menuRenderer);
    DisplayModules3(menuRenderer);

    MenuEvent ev = menuRenderer->pollEvent();

    int ret = Actions(ev);

    menuRenderer->displayy();

    if (ret == -1) { return -1;}
    if (ret == CODE_NC_PACMAN) return CODE_NC_PACMAN;
    if (ret == CODE_SDL2_PACMAN) return CODE_SDL2_PACMAN;
    if (ret == CODE_SFML_PACMAN) return CODE_SFML_PACMAN;
    if (ret == CODE_NC_SNAKE) return CODE_NC_SNAKE;
    if (ret == CODE_SDL2_SNAKE) return CODE_SDL2_SNAKE;
    if (ret == CODE_SFML_SNAKE) return CODE_SFML_SNAKE;
    return 0;
}
