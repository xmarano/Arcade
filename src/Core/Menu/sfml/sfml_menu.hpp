/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_menu.hpp
*/

#include "../../../../include/Core/Menu.hpp"

class SfmlMenu : public IMenuRenderer
{
    public:
        SfmlMenu();
        ~SfmlMenu() = default;

        MenuEvent pollEvent() override;
        void DrawText1(string text, int module, int height, int weight) override;
};
