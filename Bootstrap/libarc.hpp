/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libarc.hpp
*/

#pragma once

#include <iostream>
#include "ADisplayModule.hpp"

class Libarc : public ADisplayModule {
    public:
        Libarc();
        ~Libarc() = default;
        void init() override;
        void stop() override;
};
