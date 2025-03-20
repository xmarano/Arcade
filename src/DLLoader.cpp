/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** DLLoader.cpp
*/

#include "DLLoader.hpp"

template <typename T>
T* DLLoader<T>::getInstance(const std::string &path)
{
    if (handle != nullptr) {
        delete instance;
        dlclose(handle);
    }
    handle = dlopen(path.c_str(), RTLD_LAZY);
    if (handle == nullptr)
        throw ArcadeException(dlerror());
    typedef T* (*CreateFunc)();
    CreateFunc create = (CreateFunc)dlsym(handle, "create");
    if (create == nullptr)
        throw ArcadeException(dlerror());
    instance = create();
    return instance;
}

template <typename T>
DLLoader<T>::~DLLoader()
{
    if (handle != nullptr) {
        delete instance;
        dlclose(handle);
    }
}

// template <typename T>
// string DLLoader<T>::getLibName(const std::string &path)
// {
//     size_t pos = path.find_last_of("/");
//     string libName = path.substr(pos + 1);
//     return libName;
// }

template class DLLoader<IDisplayModule>;
