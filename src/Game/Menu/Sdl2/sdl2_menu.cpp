/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_menu.hpp"

Sdl2Menu::Sdl2Menu(SDL2 *sdl2) : sdl2(sdl2) {}

MenuEvent Sdl2Menu::pollEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return MenuEvent::Quit;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_i)
                return MenuEvent::SwapToNcurses;
            if (event.key.keysym.sym == SDLK_p)
                return MenuEvent::SwapToSfml;
            if (event.key.keysym.sym == SDLK_k)
                return MenuEvent::PlayPacman;
        }
    }
    return MenuEvent::None;
}

void Sdl2Menu::rep_event(MenuEvent event)
{
    if (event == MenuEvent::Quit) {
        this->sdl2->stop();
        exit(0);
    }
}
