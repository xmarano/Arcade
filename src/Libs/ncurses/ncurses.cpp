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
        void render(const GameState& state) {
            clear();
            for (const auto& entity : state.entities) {
                switch (entity.type) {
                    case WALL:  mvaddch(entity.y, entity.x, '#'); break;
                    case PLAYER: mvaddch(entity.y, entity.x, 'P'); break;
                    case ENEMY: mvaddch(entity.y, entity.x, 'G'); break;
                    case COIN:  mvaddch(entity.y, entity.x, '.'); break;
                    case POWERUP: mvaddch(entity.y, entity.x, '@'); break;
                }
            }
            printw("Score: %d | Lives: %d\n", state.score, state.lives);
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
