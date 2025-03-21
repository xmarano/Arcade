/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** sdl2_pacman.cpp
*/

#include "sdl2_pacman.hpp"

Sdl2Pacman::Sdl2Pacman(SDL2 *sdl2) : sdl2(sdl2) {}

void Sdl2Pacman::print_map(std::string *map, int score, int lives, int level, int highscore)
{
    ofstream file("test.txt");
    file << "test";
    (void)map;
    (void)score;
    (void)lives;
    (void)level;
    (void)highscore;
    this->sdl2->DrawText1(150, 150, "COUCOU SDL2");
}

PacmanEvent Sdl2Pacman::pollEvent(int ch)
{
    // (void)ch;
    // SDL_Event event;

    // while (SDL_PollEvent(&event)) {
    //     if (event.type == SDL_QUIT)
    //         return PacmanEvent::Quit;
    //     if (event.type == SDL_KEYDOWN) {
    //         if (event.key.keysym.sym == SDLK_q || event.key.keysym.sym == SDLK_ESCAPE)
    //             return PacmanEvent::Quit;
    //         if (event.key.keysym.sym == SDLK_i)
    //             return PacmanEvent::SwapToNcurses;
    //         if (event.key.keysym.sym == SDLK_p)
    //             return PacmanEvent::SwapToSfml;
    //     }
    // }
    return PacmanEvent::None;
}
