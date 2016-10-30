#include "../include/ThunderEngine_Video.h"
#include "../include/ThunderEngine_Util.h"

#include <SDL.h>
#include <stdexcept>
#include <iostream>

ThunderEngine::Window::Window(WindowProperties* properties)
{
	ThunderEngine::Window::properties = properties;
}

ThunderEngine::Window::~Window()
{
}

int ThunderEngine::Window::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_PrintError("SDL_Init", "init", WINDOW_INITIALIZATION_FAIL);
	}

	return WINDOW_INITIALIZATION_SUCCESS;
}

int ThunderEngine::Window::create()
{
	switch (properties->x & properties->y)
	{
	case !WINDOW_POSITION_CENTER:
		window = SDL_CreateWindow(properties->title, properties->x, properties->y, properties->width, properties->height, SDL_WINDOW_SHOWN);
		break;
	case WINDOW_POSITION_CENTER:
		window = SDL_CreateWindow(properties->title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, properties->width, properties->height, SDL_WINDOW_SHOWN);
		break;
	case WINDOW_POSITION_UNDEFINED:
		window = SDL_CreateWindow(properties->title, 0, 0, properties->width, properties->height, SDL_WINDOW_SHOWN);
		break;
	default:
		throw std::runtime_error("Window position not set!");
		break;
	}

	if (window == nullptr)
	{
		SDL_PrintError("SDL_CreateWindow", "create", WINDOW_CREATION_FAIL);
		SDL_Quit();
		SDL_ThrowError("Could not create window!");
	}
	
	SDL_SetWindowFullscreen(window, (w_fullscreen) ? SDL_WINDOW_FULLSCREEN : 0);

	return WINDOW_CREATION_SUCCESS;
}

int ThunderEngine::Window::init_context()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		SDL_PrintError("SDL_CreateRenderer", "initContext", WINDOW_RENDERER_CREATION_FAIL);
		cleanup(window);
		SDL_Quit();
		SDL_ThrowError("Could not create renderer!");
	}

	return WINDOW_RENDERER_CREATION_SUCCESS;
}

bool ThunderEngine::Window::loop_start()
{
	if (window == nullptr || renderer == nullptr)
	{
		return false;
	}

	return true;
}

void ThunderEngine::Window::delayed_close(int milli)
{
	SDL_Delay(milli);
	close_all();
}

void ThunderEngine::Window::set_title(const char* title)
{
	close_window();
	properties->title = title;
	create();
	init_context();
}

void ThunderEngine::Window::set_window_p(int x, int y)
{
	close_window();
	properties->x = x;
	properties->y = y;
	create();
	init_context();
}

void ThunderEngine::Window::set_window_wh(int width, int height)
{
	close_window();
	properties->width = width;
	properties->height = height;
	create();
	init_context();
}

void ThunderEngine::Window::set_window_properties(const char* title, int width, int height, int x, int y)
{
	close_window();
	properties->title = title;
	properties->width = width;
	properties->height = height;
	properties->x = x;
	properties->y = y;
	create();
	init_context();
}

void ThunderEngine::Window::set_window_fullscreen(bool fullscreen)
{
	w_fullscreen = fullscreen;
	if (window != nullptr)
	{
		SDL_SetWindowFullscreen(window, (w_fullscreen) ? SDL_WINDOW_FULLSCREEN : 0);
	}
}

void ThunderEngine::Window::close_window()
{
	if (window != nullptr || renderer != nullptr)
	{
		cleanup(window, renderer);
	}
}

void ThunderEngine::Window::close_all()
{
	if (window != nullptr || renderer != nullptr)
	{
		cleanup(window, renderer);
		SDL_Quit();
	}
}

bool ThunderEngine::Window::is_fullscreen()
{
	return w_fullscreen;
}

void ThunderEngine::Window::set_vfullscreen(bool fullscreen)
{
	w_fullscreen = fullscreen;
}
