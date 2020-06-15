// Abstract class to handle level
#ifndef	LEVEL_H
#define LEVEL_H

#include "Map.h"
#include "Audio.h"
#include "Timer.h"
#include "UserInput.h"
#include "GameStateManager.h"

class Level
{
public:
	// mapLevel -> file directory of the map
	Level() : nextLevel(0)
	{
		
	};
	virtual ~Level() = 0 {};

	Map GetMap()
	{
		return map;
	}

	// Init the level
	virtual void Init() {};
	// Update the level
	virtual void Update() {};
	// print out the chars
	virtual void Render() {};
	// When Exiting the level
	virtual void Exit() {};

protected:
	// Index of the next level
	int nextLevel;
	// Map to handle the current map level
	Map map;
};

#endif