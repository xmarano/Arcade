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
        TTF_Font *arcade_font;
        TTF_Font *goofy_font;
        TTF_Font *arial_font;
    public:
        SDL2();
        ~SDL2() = default;
        void init() override;
        void stop() override;
        void display() override;

        void DrawText(int pos_x, int pos_y, string mess) override;

        // void Draw_Module1() override;
        // void Draw_Module2() override;
        // void Draw_Module3() override;

        void clearScreen() override;
        void refreshScreen() override;
        int getScreenWidth() override;
        int getScreenHeight() override;
};
