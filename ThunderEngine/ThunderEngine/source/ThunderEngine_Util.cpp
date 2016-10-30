#include "../include/ThunderEngine_Util.h"

#include <stdexcept>
#include <iostream>

void ThunderEngine::SDL_PrintError(const char* method, const char* senderMethod, int returnNumber)
{
	const char* T_returnN = (const char*)returnNumber;

	std::cout << "Error occurred on method, " << senderMethod << " with, " << method << " error. Error: " << SDL_GetError();
	throw std::runtime_error(T_returnN);
}

void ThunderEngine::SDL_PrintError(const char* method, const char* senderMethod)
{
	std::cout << "Error occurred on method, " << senderMethod << " with, " << method << " error. Error: " << SDL_GetError();
}

void ThunderEngine::SDL_ThrowError(const char* msg)
{
	throw std::runtime_error(msg);
}