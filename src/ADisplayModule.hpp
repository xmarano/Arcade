/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ADisplayModule.hpp
*/

#pragma once

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

class ADisplayModule : public IDisplayModule
{
    protected:
        IGameModule *gameModule;
    public:
        ADisplayModule(const std::string &moduleName) : name(moduleName), gameModule(nullptr) {}
        ~ADisplayModule() = default;
        void setGameModule(IGameModule *game) override { gameModule = game; }
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual int display() = 0;
    private:
        std::string name;
};
