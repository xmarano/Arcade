/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libfoo.hpp
*/

#pragma once

#include "ADisplayModule.hpp"

class Libfoo : public ADisplayModule {
    public:
        Libfoo();
        ~Libfoo() = default;
        void init() override;
        void stop() override;
};
