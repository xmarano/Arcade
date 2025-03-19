/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_setup.hpp"

void SDL2::display() {
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_n) {
                    // loader.changeLibrary(current_display, "./lib/arcade_ncurses.so");
                }
            }
        }
        clearScreen();
        if (gameModule)
            gameModule->draw_game(this);
        refreshScreen();
        SDL_Delay(16);
    }
}

void SDL2::DrawText1(int pos_x, int pos_y, string mess)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface_text = TTF_RenderText_Solid(font, mess.c_str(), color);
    SDL_Texture *texture_text = SDL_CreateTextureFromSurface(renderer, surface_text);
    SDL_Rect rect_text = {pos_x, pos_y, surface_text->w, surface_text->h};

    SDL_RenderCopy(renderer, texture_text, nullptr, &rect_text);
    SDL_DestroyTexture(texture_text);
    SDL_FreeSurface(surface_text);

}

void SDL2::DrawText2(int pos_x, int pos_y, string mess)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface_text = TTF_RenderText_Solid(goofy_font, mess.c_str(), color);
    SDL_Texture *texture_text = SDL_CreateTextureFromSurface(renderer, surface_text);
    SDL_Rect rect_text = {pos_x, pos_y, surface_text->w, surface_text->h};

    SDL_RenderCopy(renderer, texture_text, nullptr, &rect_text);
    SDL_DestroyTexture(texture_text);
    SDL_FreeSurface(surface_text);

}
