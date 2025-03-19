/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_setup.cpp
*/

#include "sdl2_setup.hpp"
#include "../Game/Menu/Sdl2/sdl2_menu.hpp"
#include "../Game/Pacman/Sdl2/sdl2_pacman.hpp"

SDL2::SDL2() : ADisplayModule("SDL2") , window(nullptr), renderer(nullptr), font(nullptr)
{
    menuRenderer = new Sdl2Menu(this);
    pacmanRenderer = new Sdl2Pacman(this);
}

void SDL2::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    window = SDL_CreateWindow("Arcade - SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("Assets/Font/text.ttf", 20);
    litle_font = TTF_OpenFont("Assets/Font/little.ttf", 14);
    arcade_font = TTF_OpenFont("Assets/Font/arcade.ttf", 20);
    goofy_font = TTF_OpenFont("Assets/Font/goofy.ttf", 20);
    arial_font = TTF_OpenFont("Assets/Font/arial.ttf", 20);
}

void SDL2::stop()
{
    TTF_CloseFont(font);
    TTF_CloseFont(litle_font);
    TTF_CloseFont(arcade_font);
    TTF_CloseFont(goofy_font);
    TTF_CloseFont(arial_font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    window = nullptr;
    renderer = nullptr;
    TTF_Quit();
    SDL_Quit();
}

void SDL2::clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void SDL2::refreshScreen()
{
    SDL_RenderPresent(renderer);
}

extern "C" {
    IDisplayModule *create()
    {
        return new SDL2();
    }
}

int SDL2::getScreenWidth()
{
    int width;

    SDL_GetWindowSize(window, &width, nullptr);
    return width;
}

int SDL2::getScreenHeight()
{
    int height;

    SDL_GetWindowSize(window, nullptr, &height);
    return height;
}
