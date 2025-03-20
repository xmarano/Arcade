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

    if (ch == 'j') {
        return MenuEvent::Down;
    }
    if (ch == KEY_UP)
        return MenuEvent::Up;
    if (ch == 'q')
        return MenuEvent::Quit;
    return MenuEvent::None;
}

void NcursesMenu::rep_event(MenuEvent event)
{
    if (event == MenuEvent::Down) {
    }
    if (event == MenuEvent::Up) {
    }
    if (event == MenuEvent::Quit) {
        this->nc->stop();
        exit(0);
    }
}
