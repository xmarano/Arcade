/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_display.cpp
*/

#include "sdl2_setup.hpp"

// Event SDL2::pollEvent() {
//     SDL_Event event;
//     if (SDL_PollEvent(&event)) {
//         if (event.type == SDL_QUIT)
//             return Event::Quit;
//         if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_i)
//             return Event::SwitchToNCurses;
//         if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p)
//             return Event::SwitchToSFML;
//     }
//     return Event::None;
// }

int SDL2::display()
{
    int code = 0;

    clearScreen();
    if (gameModule) {
        code = gameModule->draw_game(this);
        if (code > 0)
            return code;
    }
    refreshScreen();
    SDL_Delay(16);
    return 0;
}

void SDL2::DrawText1(int pos_x, int pos_y, string mess)
{
    ofstream file("log.txt");
    file << "DrawText1" << endl;
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface_text = TTF_RenderText_Solid(font, mess.c_str(), color);
    SDL_Texture *texture_text = SDL_CreateTextureFromSurface(renderer, surface_text);
    SDL_Rect rect_text = {pos_x, pos_y, surface_text->w, surface_text->h};

    SDL_RenderCopy(renderer, texture_text, nullptr, &rect_text);
    SDL_DestroyTexture(texture_text);
    SDL_FreeSurface(surface_text);
}

void SDL2::DrawText2(int pos_x, int pos_y, string mess)
{
    SDL_Color color = {255, 255, 255, 255};
    SDL_Surface *surface_text = TTF_RenderText_Solid(goofy_font, mess.c_str(), color);
    SDL_Texture *texture_text = SDL_CreateTextureFromSurface(renderer, surface_text);
    SDL_Rect rect_text = {pos_x, pos_y, surface_text->w, surface_text->h};

    SDL_RenderCopy(renderer, texture_text, nullptr, &rect_text);
    SDL_DestroyTexture(texture_text);
    SDL_FreeSurface(surface_text);
}
