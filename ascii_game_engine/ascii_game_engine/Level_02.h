// Level 2 of playing map
#ifndef LEVEL_02_H
#define LEVEL_02_H

#include "FogLevels.h"

class Level_02 : public FogLevels
{
public:
	Level_02();
	~Level_02();

	// Init the level
	virtual void Init();
	// Update the level
	virtual void Update();
	// print out the chars
	virtual void Render();
	// When Exiting the level
	virtual void Exit();

private:
	// functions and variables for level 1's gameplay
};

#endif