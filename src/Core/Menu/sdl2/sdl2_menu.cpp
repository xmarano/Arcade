/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_menu.hpp"
#include <SDL2/SDL.h>

Sdl2Menu::Sdl2Menu() {}

MenuEvent Sdl2Menu::pollEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return MenuEvent::Quit;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
                return MenuEvent::Quit;
            if (event.key.keysym.sym == SDLK_k)
                return MenuEvent::PlayPacman;
            if (event.key.keysym.sym == SDLK_DOWN)
                return MenuEvent::Down;
            if (event.key.keysym.sym == SDLK_UP)
                return MenuEvent::Up;
            if (event.key.keysym.sym == SDLK_RETURN)
                return MenuEvent::Enter;
            if (event.key.keysym.sym == SDLK_BACKSPACE)
                return MenuEvent::Back;
        }
    }
    return MenuEvent::None;
}

void Sdl2Menu::DrawText1(string text, int module, int height)
{
    // recree les methode + reset le font / sprite
}
