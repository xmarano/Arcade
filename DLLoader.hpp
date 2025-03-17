/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader.hpp
*/

#pragma once

#include "IDisplayModule.hpp"

template <typename T>

class DLLoader {
    public:
        T *getInstance(const std::string &path)
        {
            void *handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!handle) {
                std::cerr << "Error: " << dlerror() << std::endl;
                return nullptr;
            }
            typedef T *(*CreateFunc)();
            CreateFunc create = (CreateFunc)dlsym(handle, "create");
            if (!create) {
                std::cerr << "Error: " << dlerror() << std::endl;
                dlclose(handle);
                return nullptr;
            }
            T *module = create();
            return module;
        }
};
