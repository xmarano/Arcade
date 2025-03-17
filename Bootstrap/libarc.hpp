/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libarc.hpp
*/

#pragma once

#include <iostream>
#include "DisplayModule.hpp"

class Libarc : public IDisplayModule {
    public:
        ~Libarc() = default;
        void init() override;
        void stop() override;
        const std::string &getName() const override;
};
