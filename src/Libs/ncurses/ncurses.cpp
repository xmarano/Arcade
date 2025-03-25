/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Ncurses.cpp
*/

#include "../../../include/Core/DisplayInterface.hpp"
#include <ncurses.h>

class NcursesDisplay : public IDisplay
{
    public:
        void init() override {
            initscr();
            noecho();
            curs_set(0);
            keypad(stdscr, TRUE);
        }

        void close() override
        {
            endwin();
        }

        void render(const GameState& state) override {
            clear();
            // appel le draw_game de pacman
            refresh();
        }

        int getInput() override {
            switch(getch()) {
                case KEY_UP:    return 0;
                case KEY_DOWN:  return 1;
                case KEY_LEFT:  return 2;
                case KEY_RIGHT: return 3;
                case 'q':       return -1;
            }
            return -2;
        }
        std::string getName() const override { return "Ncurses"; }
};

extern "C" IDisplay* create() { return new NcursesDisplay(); }
