/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Menu.hpp
*/

#pragma once

#include "IGameModule.hpp"
#include "IRenderer.hpp"

class Menu : public IGameModule {
    public:
        Menu() = default;
        ~Menu() = default;
        void draw_menu(IRenderer *renderer) override;
};
