/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <fstream>

void Menu::draw_menu(IRenderer *renderer)
{
    // int pos_x = renderer->getScreenHeight()

    renderer->DrawTitleMenu(); // Title

    renderer->Draw_Module1(); // Module 1
    renderer->Draw_Module2(); // Module 2
    renderer->Draw_Module3(); // Module 3
}
