/***********************************
*		Alex Cusaac © 2016		   
*		Name: ThunderEngine_Util		   
*		Created: 10/30/2016  
***********************************/

#pragma once

#ifndef ThunderEngine_Util_h__
#define ThunderEngine_Util_h__

#ifdef THUNDERENGINE_EXPORTS
#define THUNDERENGINE_API __declspec(dllexport)
#else
#define THUNDERENGINE_API __declspec(dllimport)
#endif

#include <SDL_video.h>
#include <SDL_surface.h>
#include <SDL_render.h>

namespace ThunderEngine
{
	void THUNDERENGINE_API SDL_PrintError(const char* method, const char* methodSender, int returnNumber);
	void THUNDERENGINE_API SDL_PrintError(const char* method, const char* methodSender);
	void THUNDERENGINE_API SDL_ThrowError(const char* msg);

	template<typename T, typename... Args>
	inline void THUNDERENGINE_API cleanup(T* t, Args&&... args)
	{
		cleanup(t);
		cleanup(std::forward<Args>(args)...);
	}

	template<>
	inline void THUNDERENGINE_API cleanup(SDL_Window* window)
	{
		if (!window)
		{
			return;
		}
		SDL_DestroyWindow(window);
	}

	template<>
	inline void THUNDERENGINE_API cleanup(SDL_Surface* surface)
	{
		if (!surface)
		{
			return;
		}
		SDL_FreeSurface(surface);
	}

	template<>
	inline void THUNDERENGINE_API cleanup(SDL_Renderer* renderer)
	{
		if (!renderer)
		{
			return;
		}
		SDL_DestroyRenderer(renderer);
	}

	template<>
	inline void THUNDERENGINE_API cleanup(SDL_Texture* texture)
	{
		if (!texture)
		{
			return;
		}
		SDL_DestroyTexture(texture);
	}
}

#endif // ThunderEngine_Util_h__