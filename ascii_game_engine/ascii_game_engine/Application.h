// Using this to handle basic application for the game
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>

#include "Game.h"

using namespace std;

class Application
{
public:
	// use to initialise objects
	void Init();
	// update loops
	void Run();
	// clear any memory
	void Exit();
};

#endif