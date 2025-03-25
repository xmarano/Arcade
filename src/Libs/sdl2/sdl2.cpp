/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** SDL2.cpp
*/

#include "../../../include/Core/DisplayInterface.hpp"
#include <SDL2/SDL.h>

class SDL2Display : public IDisplay {
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    void init() override {
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    void close() override {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void render(const GameState& state) override
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (const auto& entity : state.entities) {
            SDL_Rect rect = {entity.x * 20, entity.y * 20, 20, 20};
            switch (entity.type) {
                case WALL:  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break;
                case PLAYER: SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); break;
                case ENEMY: SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); break;
                case COIN:  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); break;
                case POWERUP: SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255); break;
            }
            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_RenderPresent(renderer);
    }


    int getInput() override {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) return -1;
            if(e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                    case SDLK_UP:    return 0;
                    case SDLK_DOWN:  return 1;
                    case SDLK_LEFT:  return 2;
                    case SDLK_RIGHT: return 3;
                }
            }
        }
        return -2;
    }
    std::string getName() const override { return "SDL2"; }
};

extern "C" IDisplay* create() { return new SDL2Display(); }
