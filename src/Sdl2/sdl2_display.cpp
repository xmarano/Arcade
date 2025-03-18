/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_setup.hpp"

void SDL2::draw_sprite(const std::string &spritePath)
{
    //?
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

void SDL2::draw_box(int width, int height)
{
    SDL_Rect rect = {pos_x, pos_y, width, height};
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);
}

void SDL2::DrawTitleMenu(const std::string &text)
{
    SDL_Color color = {255, 255, 255, 255};

    SDL_Surface *surface_title = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Surface *surface_quit = TTF_RenderText_Solid(litle_font, "Appuyer sur 'q' pour quitter", color);

    SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, surface_title);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface_quit);

    SDL_Rect rect_title = {(pos_x / 2) - 140, (pos_y / 6) - 150, surface_title->w, surface_title->h};
    SDL_Rect rect_quit = {pos_x - 180, 20, surface_quit->w, surface_quit->h};

    SDL_RenderCopy(renderer, texture_title, nullptr, &rect_title);
    SDL_RenderCopy(renderer, texture, nullptr, &rect_quit);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture_title);

    SDL_FreeSurface(surface_title);
    SDL_FreeSurface(surface_quit);
}
