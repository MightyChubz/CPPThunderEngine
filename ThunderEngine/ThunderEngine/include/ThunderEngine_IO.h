/***********************************
*		Alex Cusaac © 2016		   
*		Name: ThunderEngine_IO		   
*		Created: 10/30/2016  
***********************************/

#pragma once

#ifndef ThunderEngine_IO_h__
#define ThunderEngine_IO_h__

#ifdef THUNDERENGINE_EXPORTS
#define THUNDERENGINE_API __declspec(dllexport)
#else
#define THUNDERENGINE_API __declspec(dllimport)
#endif

#include <string>

namespace ThunderEngine
{
	std::string THUNDERENGINE_API getResourcePath(const std::string &subDir = "");
}

#endif // ThunderEngine_IO_h__