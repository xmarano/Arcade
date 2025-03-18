/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_setup.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../IRenderer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class SDL2 : public ADisplayModule, public IRenderer {
    public:
        SDL2();
        ~SDL2() = default;
        void init() override;
        void stop() override;
        void display() override;

        void drawText(int x, int y, const std::string &text) override;
        void draw_sprite(int x, int y, const std::string &spritePath) override;
        void clearScreen() override;
        void refreshScreen() override;

        int getScreenWidth() const override;
        int getScreenHeight() const override;
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
};
