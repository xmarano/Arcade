/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** sdl2.hpp
*/

#pragma once
#include "../../../include/Core/DisplayInterface.hpp"
#if defined(__linux__)
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL.h>
#elif defined(__APPLE__)
    #include <SDL_ttf.h>
    #include <SDL.h>
#endif

class Sdl2Menu;

class SDL2Display : public IDisplay
{
    private:
        Sdl2Menu *menuRenderer;
    public:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TTF_Font *font;

        SDL2Display();
        ~SDL2Display() override;

        IMenuRenderer *getMenuRenderer() override;
        void init() override;
        void close() override;
        void render(const GameState& state) override;
        void renderText(const std::string& text, int x, int y);
        int getInput() override;
        std::string getName() const override { return "SDL2"; }
        int getScreenWidth() override;
        int getScreenHeight() override;
};
