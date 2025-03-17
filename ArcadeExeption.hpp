/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Exeption.hpp
*/

#pragma once

#include <exception>
#include <string>

class ArcadeException : public std::exception
{
    public:
        ArcadeException(const std::string &message) : _message(message) {};
        const char *what() const noexcept override {return _message.c_str();}
    private:
        std::string _message;
};
