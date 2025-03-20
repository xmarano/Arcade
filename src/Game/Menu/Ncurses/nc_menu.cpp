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
    if (ch == 'i')
        return MenuEvent::SwapToSdl2;
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
