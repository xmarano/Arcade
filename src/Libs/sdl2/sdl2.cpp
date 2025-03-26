/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SDL2.cpp
*/

#include "sdl2.hpp"

void SDL2Display::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void SDL2Display::close()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDL2Display::render(const GameState &state)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for (const auto& entity : state.entities) {
        SDL_Rect rect = {entity.x * 20, entity.y * 20, 20, 20};
        // switch (entity.element) {
        //     case '#':  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break;
        //     case 'C': SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); break;
        //     case '.':  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break;
        //     case '@': SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); break;
        // }
        SDL_SetRenderDrawColor(renderer, entity.red, entity.green, entity.blue, entity.alpha);
        SDL_RenderFillRect(renderer, &rect);
    }
    SDL_RenderPresent(renderer);
}

int SDL2Display::getInput()
{
    // cout << "Ncurses input" << endl;
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT)
            return -1;
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_q: return -1;
                case SDLK_i: return 1;
                case SDLK_p: return 3;
                case SDLK_UP: return 5;
                case SDLK_DOWN: return 6;
                case SDLK_LEFT: return 7;
                case SDLK_RIGHT: return 8;
            }
        }
    }
    return 0;
}

extern "C" {
    IDisplay* create() { return new SDL2Display(); }
}
