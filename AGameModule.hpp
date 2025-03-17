/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** AGameModule.hpp
*/

#pragma once

#include "IGameModule.hpp"

class AGameModule : public IGameModule {
    public:
        AGameModule();
        ~AGameModule() = default;
        void draw_menu() override = 0;
};
