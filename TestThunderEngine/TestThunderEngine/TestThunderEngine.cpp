// TestThunderEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <window.h>
#include <iostream>

int main()
{
	using namespace ThunderEngine;

	WindowProperties properties =
	{
		"Untitled Game",
		640,
		480,
		0,
		0
	};

	Window* window = new Window(&properties);

	std::cout << window->init() << std::endl;

    return 0;
}

