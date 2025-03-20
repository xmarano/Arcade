/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.cpp
*/

#include "nc_menu.hpp"
#include <fstream>

NcursesMenu::NcursesMenu(Ncurses* nc) : nc(nc) {}

// MenuEvent NcursesMenu::pollEvent()
// {
//     int ch = getch();

//     if (ch == KEY_DOWN) {
//         ofstream file ("okok.txt");
//         file << "ok";
//         return MenuEvent::Down;
//     }
//     if (ch == KEY_UP)
//         return MenuEvent::Up;
//     return MenuEvent::None;
// }
