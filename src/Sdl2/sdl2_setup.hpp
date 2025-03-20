/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_setup.hpp
*/

#pragma once

#include "../ADisplayModule.hpp"
#include "../IRenderer.hpp"
#include "../Game/Menu/Menu.hpp"
#include "../Game/Pacman/Pacman.hpp"
#include "../DLLoader.hpp"

class SDL2 : public ADisplayModule, public IRenderer
{
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;
        TTF_Font *litle_font;
        TTF_Font *arcade_font;
        TTF_Font *goofy_font;
        TTF_Font *arial_font;
        IMenuRenderer* menuRenderer = nullptr;
        IPacmanRenderer* pacmanRenderer = nullptr;
    public:
        SDL2();
        ~SDL2() = default;
        void init() override;
        void stop() override;
        void display() override;

        IMenuRenderer* getMenuRenderer() override { return menuRenderer; };
        IPacmanRenderer* getPacmanRenderer() override { return pacmanRenderer; };
        void DrawText1(int pos_x, int pos_y, string mess) override;
        void DrawText2(int pos_x, int pos_y, string mess) override;

        void clearScreen() override;
        void refreshScreen() override;
        int getScreenWidth() override;
        int getScreenHeight() override;

        // Event pollEvent() override;
};
