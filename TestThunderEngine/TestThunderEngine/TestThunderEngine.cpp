// TestThunderEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include "ThunderEngine.h"

int main(int argc, char** argv)
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
	window->init();
	window->create();
	window->init_context();

	while (window->loop_start())
	{
		window->delayed_close(3000 * 4);
		break;
	}

    return 0;
}