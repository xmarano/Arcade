/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_setup.hpp"

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

void SDL2::DrawTitleMenu()
{
    SDL_Color color = {255, 255, 255, 255};

    SDL_Surface *surface_title = TTF_RenderText_Solid(font, "Bienvenue sur Arcade !", color);
    SDL_Surface *surface_quit = TTF_RenderText_Solid(litle_font, "Appuyer sur 'q' pour quitter", color);

    SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, surface_title);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface_quit);

    SDL_Rect rect_title = {(pos_x / 2) - 140, (pos_y / 6) - 150, surface_title->w, surface_title->h};
    SDL_Rect rect_quit = {pos_x - 200, 20, surface_quit->w, surface_quit->h};

    SDL_RenderCopy(renderer, texture_title, nullptr, &rect_title);
    SDL_RenderCopy(renderer, texture, nullptr, &rect_quit);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture_title);

    SDL_FreeSurface(surface_title);
    SDL_FreeSurface(surface_quit);
}

void SDL2::Draw_Module1()
{
    SDL_Color color = {255, 255, 255, 255};

    SDL_Surface *surface = TTF_RenderText_Solid(goofy_font, "Jeux disponibles", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {(pos_x / 3 - 280), (pos_y / 4) - 50, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    // Suite du module 1
        // Box ; Liste des jeux (sélectionable) ; get mouse pos

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void SDL2::Draw_Module2()
{
    SDL_Color color = {255, 255, 255, 255};

    SDL_Surface *surface = TTF_RenderText_Solid(goofy_font, "Profil du joueur", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {(pos_x / 3) + 220, (pos_y / 4) - 50, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void SDL2::Draw_Module3()
{
    SDL_Color color = {255, 255, 255, 255};

    SDL_Surface *surface = TTF_RenderText_Solid(goofy_font, "Affichage", color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {(pos_x / 3 + 740), (pos_y / 4) - 50, surface->w, surface->h};

    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}
