/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** sdl2.hpp
*/

#pragma once
#include "../../../include/Core/DisplayInterface.hpp"
#include <SDL2/SDL.h>

class SDL2Display : public IDisplay {
    SDL_Window* window;
    SDL_Renderer* renderer;
    public:
        ~SDL2Display() override {
            close(); // Appel explicite à close()
        }
        void init() override;

        void close() override;
        void render(const GameState& state) override;

        int getInput() override;
        std::string getName() const override { return "SDL2"; }
};
