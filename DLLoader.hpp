/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader.hpp
*/

#pragma once

#include "IDisplayModule.hpp"
#include "ArcadeExeption.hpp"

template <typename T>

class DLLoader {
    public:
        T *getInstance(const std::string &path)
        {
            void *handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!handle) {
                throw ArcadeException(dlerror());
            }
            typedef T *(*CreateFunc)();
            CreateFunc create = (CreateFunc)dlsym(handle, "create");
            if (!create) {
                throw ArcadeException(dlerror());
            }
            T *module = create();
            return module;
        }
};
