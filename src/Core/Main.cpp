/*
** EPITECH PROJECT, 2024
** My_arc
** File description:
** Main.cpp
*/

#include "../include/Core/DisplayInterface.hpp"
#include "../include/Core/GameInterface.hpp"
#include "../include/Core/DLLoader.hpp"
#include "../include/Core/Menu.hpp"
#include "../include/Core/Launcher.hpp"
#include "../include/Core/ArcadeException.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char **argv)
{
    try {
        if (argc == 2 && std::string(argv[1]) == "unitest") return 0;
        if (argc != 2) throw ArcadeException("Usage: ./arcade ./lib/lib.so");
        std::string temp_file_path = argv[1];
        if (!std::filesystem::exists(temp_file_path)) throw ArcadeException("Library not found");
        std::string file_path = temp_file_path.substr(temp_file_path.find_last_of("/") + 1);
        if (file_path != "arcade_ncurses.so" && file_path != "arcade_sfml.so" && file_path != "arcade_sdl2.so") throw ArcadeException("Wrong library");

        Launcher launcher(argv[1]);
        return launcher.run();

    } catch (ArcadeException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }
}
