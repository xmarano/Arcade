/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_pacman.cpp
*/

#include "sdl2_snake.hpp"
#include "../../../Sdl2/sdl2_setup.hpp"

Sdl2Snake::Sdl2Snake(SDL2 *sdl2) : sdl2(sdl2) {}

void Sdl2Snake::print_map(string *map)
{
    // int y = this->sdl2->getScreenHeight() / 2;
    // int x = this->sdl2->getScreenWidth() / 2;

    this->sdl2->DrawText2(0, 0, "COUCOU SNAKE");
}

SnakeEvent Sdl2Snake::pollEvent()
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return SnakeEvent::Quit;
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
                return SnakeEvent::Quit;
            if (event.key.keysym.sym == SDLK_i)
                return SnakeEvent::SwapToNcurses;
            if (event.key.keysym.sym == SDLK_p)
                return SnakeEvent::SwapToSfml;
            if (event.key.keysym.sym == SDLK_UP)
                return SnakeEvent::UP;
            if (event.key.keysym.sym == SDLK_DOWN)
                return SnakeEvent::Down;
            if (event.key.keysym.sym == SDLK_LEFT)
                return SnakeEvent::Left;
            if (event.key.keysym.sym == SDLK_RIGHT)
                return SnakeEvent::Right;
        }
    }
    return SnakeEvent::None;
}

void Sdl2Snake::quit()
{
    this->sdl2->stop();
    exit(0);
}
