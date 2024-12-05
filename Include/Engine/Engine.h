#pragma once
#include <SDL3/SDL.h>

class Engine{
public: 
	/** Starts up SDL and creates a window */
	bool init();

	/** Loads media */
	bool loadMedia();

	/** Frees media and shuts down SDL*/
	void close();
	bool tick();

	SDL_Window* Window {nullptr};

	SDL_Surface* ScreenSurface {nullptr};

	SDL_Surface* HelloWorld {nullptr};

	// TODO: These should not be public.
	int ScreenWidth {640};
	int ScreenHeight {480};	
};
