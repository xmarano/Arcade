/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader.hpp
*/

#pragma once

#include "dlfcn.h"
#include "ArcadeExeption.hpp"
#include "ADisplayModule.hpp"

template <typename T>

class DLLoader
{
    private:
        void* handle = nullptr;
        T* instance = nullptr;
    public:
        DLLoader() = default;
        ~DLLoader();
        T* getInstance(const std::string &path);
};
