/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** IGameModule.hpp
*/

#pragma once

#include <iostream>
#include <fstream>
#include "IRenderer.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual int draw_game(IRenderer *renderer) = 0;
        virtual std::string get_game_name() = 0;
};
