/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_setup.hpp"

void SDL2::draw_sprite(int x, int y, const std::string &spritePath)
{

}

void SDL2::display()
{
    clearScreen();
    if (gameModule) {
        gameModule->draw_menu(this);
    }
    refreshScreen();
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_q)) {
                running = false;
            }
        }
        SDL_Delay(16);
    }
}

void SDL2::drawText(int x, int y, const std::string &text)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
