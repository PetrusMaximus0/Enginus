#include <filesystem>
#include <fstream>
#include <Engine/Engine.h> 
#include <iostream>

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
}
