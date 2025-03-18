/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_setup.cpp
*/

#include "ncurses_setup.hpp"

Ncurses::Ncurses() : ADisplayModule("Ncurses") {}

Ncurses::~Ncurses()
{
    stop();
}

void Ncurses::setTerminalTitle(string title)
{
    std::cout << "\033]0;" << title << "\007";
}

void Ncurses::init()
{
    setTerminalTitle("Arcade");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    getScreenHeight();
    getScreenWidth();
}

void Ncurses::stop()
{
    endwin();
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

void Ncurses::getScreenWidth()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    pos_x = maxX;
}

void Ncurses::getScreenHeight()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    pos_y = maxY;
}
