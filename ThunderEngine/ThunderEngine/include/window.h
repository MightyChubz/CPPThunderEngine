/***********************************
*		Alex Cusaac © 2016		   
*		Name: window		   
*		Created: 10/29/2016  
***********************************/

#pragma once

#ifndef window_h__
#define window_h__

#ifdef THUNDERENGINE_EXPORTS
#define THUNDERENGINE_API __declspec(dllexport)
#else
#define THUNDERENGINE_API __declspec(dllimport)
#endif

#include <SDL_video.h>
#include <SDL_render.h>

namespace ThunderEngine
{
	enum WindowState
	{
		WINDOW_CREATION_SUCCESS = 0X00,
		WINDOW_CREATION_FAIL = 0X01,
		WINDOW_INITIALIZATION_SUCCESS = 0x00,
		WINDOW_INITIALIZATION_FAIL = 0x02,
		WINDOW_RENDERER_CREATION_SUCCESS = 0x00,
		WINDOW_RENDERER_CREATION_FAIL = 0x03
	};

	enum THUNDERENGINE_API WindowPosition
	{
		WINDOW_POSITION_CENTER = 0x100,
		WINDOW_POSITION_UNDEFINED = 0x200
	};

	struct THUNDERENGINE_API WindowProperties
	{
		const char* title;
		int width;
		int height;
		int x;
		int y;
	};

	class THUNDERENGINE_API Window
	{
	public:
		Window(WindowProperties* properties);
		~Window();

		int init();
		int create();
		void loopStart();
	private:
		WindowProperties* properties;

		SDL_Window* window;
		SDL_Renderer* renderer;

		int initContext();
	protected:
		void update();
		void render();
	};
}

#endif // window_h__
