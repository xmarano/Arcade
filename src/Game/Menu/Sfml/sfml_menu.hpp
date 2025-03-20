/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sfml_menu.hpp
*/

#include "../Menu.hpp"

class SfmlMenu : public IMenuRenderer
{
    private:
        Sfml *sfml;
    public:
        SfmlMenu(Sfml *sfml);
        ~SfmlMenu() = default;

        MenuEvent pollEvent() override;
        void rep_event(MenuEvent event) override;
};
