#include "../include/window.h"
#include "../include/util.h"

#include <SDL.h>
#include <stdexcept>

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
		SDLPrintError("SDL_Init", "init", WINDOW_INITIALIZATION_FAIL);
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
		SDLPrintError("SDL_CreateWindow", "create", WINDOW_CREATION_FAIL);
		SDL_Quit();
		ThrowSDLError("Could not create window!");
	}

	return WINDOW_CREATION_SUCCESS;
}

int ThunderEngine::Window::initContext()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		SDLPrintError("SDL_CreateRenderer", "initContext", WINDOW_RENDERER_CREATION_FAIL);
		SDL_DestroyWindow(window);
		SDL_Quit();
		ThrowSDLError("Could not create renderer!");
	}

	return WINDOW_RENDERER_CREATION_SUCCESS;
}

void ThunderEngine::Window::loopStart()
{
}

void ThunderEngine::Window::update()
{
}

void ThunderEngine::Window::render()
{
}
