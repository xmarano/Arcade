/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Encap.hpp
*/
#include "DLLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

#pragma once

enum class Event {
    None,
    Quit,
    SwitchToSDL2,
    SwitchToNCurses,
    SwitchToSFML
};
