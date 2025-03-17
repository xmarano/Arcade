/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_setup.cpp
*/

#include "ncurses_setup.hpp"
#include <ncurses.h>

Ncurses::Ncurses() : ADisplayModule("Ncurses") {}

Ncurses::~Ncurses() {
    stop();
}

void Ncurses::init() {
    initscr();            // Initialise Ncurses
    cbreak();             // Désactive la mise en mémoire tampon de ligne
    noecho();             // Désactive l'affichage des caractères saisis
    keypad(stdscr, TRUE); // Active la lecture des touches spéciales (flèches, etc.)
    curs_set(0);          // Masque le curseur
}

void Ncurses::stop()
{
    endwin();
}

void Ncurses::display() {
    clear();
    if (gameModule) {
        gameModule->draw_menu(this); // Dessine le menu
    }
    mvprintw(20, 10, "Appuyez sur 'q' pour quitter...");
    refresh();
    while (true) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }
}

void Ncurses::drawText(int x, int y, const std::string &text)
{
    mvprintw(y, x, "%s", text.c_str());
}

void Ncurses::clearScreen()
{
    clear();
}

void Ncurses::refreshScreen()
{
    refresh();
}

extern "C" {
    IDisplayModule *create()
    {
        return new Ncurses();
    }
}

int Ncurses::getScreenWidth() const
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxX;
}

int Ncurses::getScreenHeight() const
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxY;
}
