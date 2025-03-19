/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_pacman.hpp
*/

#pragma once

#include "../Pacman.hpp"

class Sdl2Pacman : public IPacmanRenderer
{
    private:
        SDL2 *sdl2;
    public:
        Sdl2Pacman(SDL2 *sdl2);;
        ~Sdl2Pacman() = default;

        int load_map_from_file(std::string filename) override;
        void move_player() override;
};
