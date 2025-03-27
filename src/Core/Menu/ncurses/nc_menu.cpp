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

    return MenuEvent::None;
}

void NcursesMenu::DrawText1(string text, int module, int height)
{
    mvprintw(height, 0, text.c_str());
    // int screenWidth = getmaxx(stdscr);
    // int screenHeight = getmaxy(stdscr);
    // int y = (screenHeight / 10 * height);
    // string error = "!-- ERROR DISPLAY --!";

    // if (module == 0) {
    //     mvprintw(y, (screenWidth / 2) - (text.length() / 2), text.c_str());
    // } else if (module == 1) {
    //     mvprintw(y, ((screenWidth / 3) / 2) - (text.length() / 2), text.c_str());
    // } else if (module == 2) {
    //     mvprintw(y, ((screenWidth / 1) / 2) - (text.length() / 2), text.c_str());
    // } else if (module == 3) {
    //     mvprintw(y, ((screenWidth / 3) * 2.5) - (text.length() / 2), text.c_str());
    // } else {
    //     mvprintw(y, (screenWidth / 2) - (error.length() / 2), error.c_str());
    // }
}
