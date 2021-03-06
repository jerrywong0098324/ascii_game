// Using this to handle basic application for the game
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>

#include "Game.h"
#include "Timer.h"
#include "LevelManager.h"
#include "GameStateManager.h"
#include "Renderer.h"
#include "Mouse.h"

class Application
{
public:
	Application() {}; // construtor -> function will be called when i create an object
	~Application() {}; // destructor

	// use to initialise objects
	void Init();
	// update loops
	void Run();
	// clear any memory
	void Exit();
	// Clear all memory when cross button is pressed
	void Terminate();
};

#endif