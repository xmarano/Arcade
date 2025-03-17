/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ADisplayModule.hpp
*/

#pragma once

#include "IDisplayModule.hpp"

class ADisplayModule : public IDisplayModule
{
    private:
        std::string name;
    public:
        ADisplayModule(const std::string &moduleName) : name(moduleName) {};
        ~ADisplayModule() = default;
        const std::string &getName() const {return name;}
        void init() override = 0;
        void stop() override = 0;
        void display() override = 0;
};
