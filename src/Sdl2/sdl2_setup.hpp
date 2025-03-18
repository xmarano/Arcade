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
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
        TTF_Font *litle_font;
        int pos_x;
        int pos_y;
    public:
        SDL2();
        ~SDL2() = default;
        void init() override;
        void stop() override;
        void display() override;

        void DrawTitleMenu(const std::string &text) override;
        void draw_sprite(const std::string &spritePath) override;
        void draw_box(int width, int height) override;

        void clearScreen() override;
        void refreshScreen() override;
        void getScreenWidth() override;
        void getScreenHeight() override;
};
