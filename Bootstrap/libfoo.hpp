/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** libfoo.hpp
*/

#pragma once

#include "DisplayModule.hpp"

class Libfoo : public IDisplayModule {
    private:
        void *entryPoint;
    public:
        ~Libfoo() = default;
        void init() override;
        void stop() override;
        const std::string &getName() const override;
};
