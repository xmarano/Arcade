/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_menu.hpp"
#include "../../../Libs/sdl2/sdl2.hpp"

Sdl2Menu::Sdl2Menu(SDL2Display *disp) : display(disp), pos_x(0), pos_y(0) {}

MenuEvent Sdl2Menu::pollEvent()
{
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            return MenuEvent::Quit;
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_q: return MenuEvent::Quit;
                case SDLK_UP: return MenuEvent::Up;
                case SDLK_DOWN: return MenuEvent::Down;
                case SDLK_RETURN: return MenuEvent::Enter;
                case SDLK_BACKSPACE: return MenuEvent::Back;
            }
        }
    }
    return MenuEvent::None;
}

void Sdl2Menu::DrawText1(string text, int module, int x, int y)
{
    SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 255);
    SDL_RenderClear(display->renderer);
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(display->font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(display->renderer, surface);
    SDL_Rect dest = {x, y, surface->w, surface->h};
    SDL_RenderCopy(display->renderer, texture, NULL, &dest);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    SDL_RenderPresent(display->renderer);
}
