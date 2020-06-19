// Level 1 of playable map
#ifndef LEVEL_01_H
#define LEVEL_01_H

#include "PlayableLevels.h"

class Level_01 : public PlayableLevels
{
public:
	Level_01();
	~Level_01();

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