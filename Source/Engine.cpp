#include <filesystem>
#include <fstream>
#include <Engine/Engine.h> 
#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

void Engine::PrintHello()
{
    //
    std::cout << "Hello from the Engine!\n";

    //
    std::ifstream engine_config("./Engine/Config/config.txt");
    if (engine_config.is_open())
    {
        std::cout << engine_config.rdbuf() << "\n"; 
    }else
    {
        std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
        std::cout << "Could not open the engine config file.\n";
    }

    //Initialize SDL window and renderer
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystems Initialized... " << std::endl;
        auto Window = SDL_CreateWindow("SDL TEST", 0, 0, 400, 400, false);

        if (Window) {
            std::cout << "Window Created..." << std::endl;
            auto Renderer = SDL_CreateRenderer(Window, NULL);

            if (Renderer) {
                std::cout << "Renderer Created" << std::endl;
                SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
            }
        }
    }
}
