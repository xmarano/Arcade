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
        void Draw_Module1() override;
        void Draw_Module2() override;
        void Draw_Module3() override;
};
