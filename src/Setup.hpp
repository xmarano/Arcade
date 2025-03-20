/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Encap.hpp
*/

#pragma once

#include "DLLoader.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

enum class Event {
    None,
    Quit,
    SwitchToSDL2,
    SwitchToNCurses,
    // Up,
    // Down
};
