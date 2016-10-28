#pragma once

#ifndef game_h__
#define game_h__

#ifndef THUNDERENGINE_EXPORTS
#define THUNDERENGINE_API __declspec(dllimport);
#else
#define THUNDERENGINE_API __declspec(dllexport);
#endif // THUNDERENGINE_EXPORTS

namespace ThunderEngine
{
	struct THUNDERENGINE_API WindowProperties
	{
		const char* title;
		int width;
		int height;
		int x;
		int y;
	};
}

#endif // game_h__
