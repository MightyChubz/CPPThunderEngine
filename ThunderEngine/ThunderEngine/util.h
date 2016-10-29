/***********************************
*		Alex Cusaac © 2016		   
*		Name: util		   
*		Created: 10/29/2016  
***********************************/

#pragma once

#ifndef util_h__
#define util_h__

#ifdef THUNDERENGINE_EXPORTS
#define THUNDERENGINE_API __declspec(dllexport)
#else
#define THUNDERENGINE_API __declspec(dllimport)
#endif

void SDLPrintError(const char* method, const char* methodSender, int returnNumber);
void SDLPrintError(const char* method, const char* methodSender);
void ThrowSDLError(const char* msg);

#endif // util_h__