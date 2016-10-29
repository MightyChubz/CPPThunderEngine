#include "util.h"
#include <SDL_error.h>
#include <iostream>

void SDLPrintError(const char* method, const char* senderMethod, int returnNumber)
{
	const char* T_returnN = (const char*) returnNumber;

	std::cout << "Error ocurred on method, " << senderMethod << " with, " << method << " error. Error: " << SDL_GetError();
	throw std::runtime_error(T_returnN);
}

void SDLPrintError(const char* method, const char* senderMethod)
{
	std::cout << "Error ocurred on method, " << senderMethod << " with, " << method << " error. Error: " << SDL_GetError();
}

void ThrowSDLError(const char* msg)
{
	throw std::runtime_error(msg);
}
