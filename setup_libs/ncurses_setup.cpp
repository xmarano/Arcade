/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include "ncurses_setup.hpp"
#include <ncurses.h>
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

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    if (has_colors()) {
        start_color();
    }
    timeout(0);
}

void Ncurses::display()
{

}

void Ncurses::stop()
{
    endwin();
    cout << "[ncurses] ncurses stopping ..." << endl;
}
