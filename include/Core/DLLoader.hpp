/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** DLLoader.hpp
*/

#pragma once
#include <dlfcn.h>
#include <string>
#include <stdexcept>

template <typename T>
class DLLoader {
    private:
        void* handle;
        T* instance;
    public:
        DLLoader() : handle(nullptr), instance(nullptr) {}
        T* load(const std::string& path) {
            if (handle) dlclose(handle);
            handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!handle) throw std::runtime_error(dlerror());
            auto create = reinterpret_cast<T*(*)()>(dlsym(handle, "create"));
            if (!create) throw std::runtime_error(dlerror());
            instance = create();
            return instance;
        }
        ~DLLoader() {
            if (handle) {
                delete instance;
                dlclose(handle);
            }
        }
};
