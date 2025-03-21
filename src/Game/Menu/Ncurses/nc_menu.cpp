/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.cpp
*/

#include "nc_menu.hpp"
#include <fstream>

NcursesMenu::NcursesMenu(Ncurses* nc) : nc(nc) {}

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
    if (ch == 127) // A fix
        return MenuEvent::Back;

    return MenuEvent::None;
}

void NcursesMenu::rep_event(MenuEvent event)
{
    if (event == MenuEvent::Quit) {
        this->nc->stop();
        exit(0);
    }
}
