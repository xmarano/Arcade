/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include "ncurses_setup.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <unistd.h>
#include <cstring>

extern "C" IDisplayModule* create()
{
    return new Ncurses();
}

Ncurses::Ncurses() : ADisplayModule("ncurses")
{
    return;
}

void Ncurses::init()
{
    std::cout << "[ncurses] Entry point for ncurses !" << std::endl;

    // Initialisation de ncurses
    initscr();            // Initialise ncurses
    cbreak();             // Désactive la mise en mémoire tampon de ligne
    noecho();             // Désactive l'affichage des caractères saisis
    keypad(stdscr, TRUE); // Active la lecture des touches spéciales
    if (has_colors()) {
        start_color(); // Active les couleurs si disponibles
    }
    timeout(0);
}

void Ncurses::display()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    // Boucle principale
    while (true) {
        clear();

        const char *message = "Hello World !!!";
        int message_length = strlen(message);
        int y = max_y / 2;
        int x = (max_x - message_length) / 2;

        mvprintw(y, x, "%s", message);
        refresh();

        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            break;
        }
        usleep(100000);
    }
}

void Ncurses::stop()
{
    endwin();
    cout << "[ncurses] ncurses stopping ..." << endl;
}
