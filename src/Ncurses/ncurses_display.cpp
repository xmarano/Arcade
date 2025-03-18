/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_display.cpp
*/

#include "ncurses_setup.hpp"

void Ncurses::display()
{
    cout << "Displaying Ncurses" << endl;
    clear();
    if (gameModule) {
        gameModule->draw_menu(this);
    }
    refresh();
    while (true) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }
}

void Ncurses::DrawText1(int pos_x, int pos_y, string mess)
{
    mvprintw(pos_y, pos_x, "%s", mess.c_str());
}

void Ncurses::DrawText2(int pos_x, int pos_y, string mess)
{
    DrawText1(pos_x, pos_y, mess);
}

// void Ncurses::Draw_Module1()
// {
//     mvprintw((pos_y / 7), (pos_x / 4) - 10, "Jeux disponibles");

//     // Box
// }

// void Ncurses::Draw_Module2()
// {
//     // mvprintw(2, (pos_x / 2) - 10, "Profil du joueur");
// }

// void Ncurses::Draw_Module3()
// {
//     // mvprintw(3, (pos_x / 2) - 10, "Affichage");
// }
