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
        static IDisplayModule* currentDisplayModule;
    public:
        ADisplayModule(const std::string &moduleName);
        ~ADisplayModule() = default;
        const std::string &getName() const;
        void setGameModule(IGameModule *game) override;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual void display() = 0;
        static void setCurrentDisplayModule(IDisplayModule* module);
        static IDisplayModule* getCurrentDisplayModule();
    private:
        std::string name;
};
