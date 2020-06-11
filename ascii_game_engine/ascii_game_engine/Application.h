// Using this to handle basic application for the game
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <conio.h>
#include <string>

#include "Game.h"
#include "Timer.h"
#include "LevelManager.h"
#include "GameStateManager.h"
#include "AudioManager.h"

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