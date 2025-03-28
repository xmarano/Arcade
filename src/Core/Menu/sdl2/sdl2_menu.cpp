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
                case SDLK_h: return MenuEvent::PlayPacman;
            }
        }
    }
    return MenuEvent::None;
}

void Sdl2Menu::DrawText1(int pos_x, int pos_y, string text)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Blended(display->font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(display->renderer, surface);
    SDL_Rect dest = {pos_x, pos_y, surface->w, surface->h};
    SDL_RenderCopy(display->renderer, texture, NULL, &dest);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Sdl2Menu::clearScreen()
{
    SDL_RenderClear(display->renderer);
}

void Sdl2Menu::displayy()
{
    SDL_RenderPresent(display->renderer);
}
