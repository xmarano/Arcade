/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.cpp
*/

#include "nc_menu.hpp"
#include <fstream>
#include <ncurses.h>

NcursesMenu::NcursesMenu() {}

MenuEvent NcursesMenu::pollEvent()
{
    int ch = getch();

    if (ch == 'q')
        return MenuEvent::Quit;
    if (ch == KEY_UP)
        return MenuEvent::Up;
    if (ch == KEY_DOWN)
        return MenuEvent::Down;
    if (ch == '\n')
        return MenuEvent::Enter;
    if (ch == 127 || ch == KEY_BACKSPACE)
        return MenuEvent::Back;
    if (ch == 'h')
        return MenuEvent::PlayPacman;
    return MenuEvent::None;
}

void NcursesMenu::DrawText1(int pos_x, int pos_y, string text)
{
    mvprintw(pos_y, pos_x, text.c_str());
    refresh();
}

void NcursesMenu::clearScreen() {
    clear();
}
