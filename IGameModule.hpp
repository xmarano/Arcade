/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule.hpp
*/

#pragma once

#include <iostream>

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual void draw_menu() = 0;
};
