// Using this to handle basic application for the game
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <conio.h>
//#include <Windows.h>
#include <string>

#include "UserInput.h"
#include "Game.h"
#include "Timer.h"

class Application
{
public:
	Application() {};
	~Application() {};

	// use to initialise objects
	void Init();
	// update loops
	void Run();
	// clear any memory
	void Exit();
};

#endif