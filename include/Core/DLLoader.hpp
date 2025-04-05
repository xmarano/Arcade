/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** DLLoader.hpp
*/

#pragma once
#include <dlfcn.h>
#include <string>
#include <stdexcept>
#include "ArcadeException.hpp"

template <typename T>
class DLLoader {
    private:
        void* m_handle = nullptr;
        T* m_instance = nullptr;
    public:
        /**
        * @brief Loads a dynamic library at runtime.
        * @param path Path to the .so file.
        * @return Pointer to the loaded library instance.
        * @throws ArcadeException if loading fails.
        */
        T* load(const std::string& path) {
            if (m_handle) {
                dlclose(m_handle);
            }
            m_handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!m_handle)
                throw ArcadeException(dlerror());
            auto create = reinterpret_cast<T*(*)()>(dlsym(m_handle, "create"));
            if (!create)
                throw ArcadeException(dlerror());

            m_instance = create();
            return m_instance;
        }

        ~DLLoader() {
            if (m_handle) {
                dlclose(m_handle);
            }
        }
};
