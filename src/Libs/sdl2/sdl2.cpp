/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SDL2.cpp
*/

#include "sdl2.hpp"
#include "../../../src/Core/Menu/sdl2/sdl2_menu.hpp"

SDL2Display::SDL2Display() : menuRenderer(nullptr) {}

SDL2Display::~SDL2Display()
{
    if (menuRenderer) {
        delete menuRenderer;
    }
    close();
}

IMenuRenderer* SDL2Display::getMenuRenderer()
{
    if (!menuRenderer) {
        menuRenderer = new Sdl2Menu(this);
    }
    return static_cast<IMenuRenderer*>(menuRenderer);
}

void SDL2Display::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Arcade - sdl2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
    font = TTF_OpenFont("Assets/Font/goofy.ttf", 24);
}

void SDL2Display::close()
{
    if (window) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        TTF_Quit();
    }
}

void SDL2Display::render(const GameState &state)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for (const auto& entity : state.entities) {
        SDL_Rect rect = {entity.x * 20, entity.y * 20, 20, 20};
        SDL_SetRenderDrawColor(renderer, entity.red, entity.green, entity.blue, entity.alpha);
        SDL_RenderFillRect(renderer, &rect);
    }
    
    // Affichage du score et du niveau
    renderText("Score: " + std::to_string(state.score), 20, 20);
    renderText("Level: " + std::to_string(state.level), 20, 50);
    
    SDL_RenderPresent(renderer);
}

void SDL2Display::renderText(const std::string &text, int x, int y)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dest = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

int SDL2Display::getInput()
{
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
                case SDLK_RETURN: return 10;
            }
        }
    }
    return 0;
}

int SDL2Display::getScreenWidth()
{
    int width;

    SDL_GetWindowSize(window, &width, nullptr);
    return width;
}

int SDL2Display::getScreenHeight()
{
    int height;

    SDL_GetWindowSize(window, nullptr, &height);
    return height;
}


extern "C" {
    IDisplay* create() { return new SDL2Display(); }
}
