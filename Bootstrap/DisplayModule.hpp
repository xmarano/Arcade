/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DisplayModule.hpp
*/

#pragma once

#include <dlfcn.h>
#include <iostream>

using namespace std;

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void init() = 0;
        virtual void stop() = 0;
        virtual const string &getName() const = 0;
};
