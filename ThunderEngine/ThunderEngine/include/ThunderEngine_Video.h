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
	enum WindowState : int
	{
		WINDOW_CREATION_SUCCESS = 0X00,
		WINDOW_CREATION_FAIL = 0X01,
		WINDOW_INITIALIZATION_SUCCESS = 0x00,
		WINDOW_INITIALIZATION_FAIL = 0x02,
		WINDOW_RENDERER_CREATION_SUCCESS = 0x00,
		WINDOW_RENDERER_CREATION_FAIL = 0x03
	};

	enum THUNDERENGINE_API WindowPosition : int
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
		int init_context();
		bool loop_start();
		void delayed_close(int milli);
		void set_title(const char* title);
		void set_window_p(int x, int y);
		void set_window_wh(int width, int height);
		void set_window_properties(const char* title, int width, int height, int x, int y);
		void set_window_fullscreen(bool fullscreen);
		void close_window();
		void close_all();
		bool is_fullscreen();
		void set_vfullscreen(bool fullscreen);
	private:
		bool w_fullscreen = false;
		WindowProperties* properties;

		SDL_Window* window;
		SDL_Renderer* renderer;
	};
}

#endif // window_h__
