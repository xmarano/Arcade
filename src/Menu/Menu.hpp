/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.hpp
*/

#pragma once

#include "../IGameModule.hpp"
#include "../ArcadeExeption.hpp"
#include "../Sdl2/sdl2_setup.hpp"
#include "../Game/Pacman/Pacman.hpp"
#include <vector>
#include "../Ncurses/ncurses_setup.hpp"
#include "../Sfml/sfml_setup.hpp"

class Pacman;

enum class MenuEvent {
    None,
    Quit,
    Up,
    Down,
    Enter,
    Back,
    PlayPacman,
    PlaySnake,
    SwapToNcurses,
    SwapToSfml,
    SwapToSdl2
};

class Menu
{
    private:
        pair<int, int> current;
        pair<int, int> selectedOption;
        bool isUsernameSet;
        DLLoader<IGameModule> gameLoader;
        IGameModule *game;
    public:
        Menu();
        ~Menu();
        int draw_game(IRenderer *renderer) override;
        void DisplayText(IRenderer *renderer, string text, int module, int height);
        void DisplayModules1(IRenderer *renderer);
        void DisplayModules2(IRenderer *renderer);
        void DisplayModules3(IRenderer *renderer);
        int Actions(IRenderer *renderer, MenuEvent ev);
        vector<string> get_stats();

        std::string get_game_name() override { return "Menu"; }
};

class IMenuRenderer {
    public:
        virtual ~IMenuRenderer() = default;
        virtual MenuEvent pollEvent() = 0;

        virtual void rep_event(MenuEvent event) = 0;

};
