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

template <typename T>
class DLLoader {
    private:
        void* m_handle = nullptr;
        T* m_instance = nullptr;
    public:
        T* load(const std::string& path) {
            if (m_handle) {
                dlclose(m_handle);
            }
            m_handle = dlopen(path.c_str(), RTLD_LAZY);
            if (!m_handle)
                throw std::runtime_error(dlerror());
            auto create = reinterpret_cast<T*(*)()>(dlsym(m_handle, "create"));
            if (!create)
                throw std::runtime_error(dlerror());

            m_instance = create();
            return m_instance;
        }

        ~DLLoader() {
            if (m_handle) {
                dlclose(m_handle);
            }
        }
};
