/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** DLLoader.cpp
*/

#include "../../include/Core/DLLoader.hpp"

// template <typename T>
// T* DLLoader<T>::load(const std::string& path) {
//     if (handle)
//         dlclose(handle);
//     handle = dlopen(path.c_str(), RTLD_LAZY);
//     if (!handle)
//         throw std::runtime_error(dlerror());
//     auto create = reinterpret_cast<T*(*)()>(dlsym(handle, "create"));
//     if (!create)
//         throw std::runtime_error(dlerror());
//     instance = create();
//     return instance;
// }

// template <typename T>
// DLLoader<T>::~DLLoader() {
//     if (handle) {
//         delete instance;
//         dlclose(handle);
//     }
// }
