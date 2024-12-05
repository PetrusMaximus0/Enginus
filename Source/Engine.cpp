#include <filesystem>
#include <Engine/Engine.h>

/** Starts up SDL and creates a window */
bool Engine::init(){ 
    // Initialize SDL VIDEO
    if (!SDL_Init(SDL_INIT_VIDEO)){
        SDL_Log("SDL Could not initialize! SDL error: %s\n", SDL_GetError());
        return false;
    }

    Window = SDL_CreateWindow("SDL3 Tutorial: Hello SDL3", ScreenWidth, ScreenHeight, 0);

    if (Window == nullptr){
        SDL_Log("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    
    ScreenSurface = SDL_GetWindowSurface(Window);
    
    return true;
}

/** Loads media */
bool Engine::loadMedia()
{
    return false;
}

/** Frees media and shuts down SDL*/
void Engine::close()
{
    //Clean up surface
    //SDL_DestroySurface( HelloWorld );
    //HelloWorld = nullptr;
    
    //Destroy window
    SDL_DestroyWindow( Window );
    Window = nullptr;
    ScreenSurface = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}

bool Engine::tick()
{
    //The event data
    SDL_Event e;
    SDL_zero( e );
    
    //Get event data
    while( SDL_PollEvent( &e ) )
    {
        //If event is quit type
        if( e.type == SDL_EVENT_QUIT )
        {
            //End the main loop
           return true;
        }
    }
    //Fill the surface white
    SDL_FillSurfaceRect( ScreenSurface, nullptr, SDL_MapSurfaceRGB( ScreenSurface, 0xFF, 0xFF, 0xFF ) );
            
    //Render image on screen
    SDL_BlitSurface( HelloWorld, nullptr, ScreenSurface, nullptr );

    //Update the surface
    SDL_UpdateWindowSurface( Window );

    return false;
}
