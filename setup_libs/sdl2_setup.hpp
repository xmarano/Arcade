/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Sdl2.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"

class Sdl2 : public ADisplayModule {
    public:
        Sdl2();
        ~Sdl2() = default;
        void init() override;
        void stop() override;
        void display() override;
};
