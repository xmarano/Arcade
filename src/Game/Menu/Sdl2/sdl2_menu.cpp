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
            if (event.key.keysym.sym == SDLK_DOWN)
                return MenuEvent::Down;
            if (event.key.keysym.sym == SDLK_UP)
                return MenuEvent::Up;
        }
    }
    return MenuEvent::None;
}
