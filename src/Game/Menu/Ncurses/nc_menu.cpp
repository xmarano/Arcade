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
    if (ch == 'o')
        return MenuEvent::SwapToSdl2;
    if (ch == 'p')
        return MenuEvent::SwapToSfml;
    if (ch == 'k')
        return MenuEvent::PlayPacman;
    return MenuEvent::None;
}

void NcursesMenu::rep_event(MenuEvent event)
{
    if (event == MenuEvent::Quit) {
        this->nc->stop();
        exit(0);
    }
}
