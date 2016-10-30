#include "../include/ThunderEngine_IO.h"

#include <iostream>
#include <SDL_filesystem.h>
#include <SDL_stdinc.h>
#include <SDL_error.h>

std::string ThunderEngine::getResourcePath(const std::string &subDir /*= ""*/)
{
	#ifdef _WIN32
	const char PATH_SEP = '\\';
	#else
	const char PATH_SEP = '/';
	#endif // _WIN32

	static std::string baseRes;
	if (baseRes.empty())
	{
		char* basePath = SDL_GetBasePath();
		if (basePath)
		{
			baseRes = basePath;
			SDL_free(basePath);
		}
		else
		{
			std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
			return "";
		}

		size_t pos = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
	}

	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEP;
}
