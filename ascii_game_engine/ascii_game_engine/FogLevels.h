// Playable levels with fog in it
#ifndef FOG_LEVELS_H
#define FOG_LEVELS_H

#include "Fog.h"
#include "PlayableLevels.h"

class FogLevels : public PlayableLevels
{
public:
	FogLevels();
	~FogLevels() = 0;

	/*******************************************************************
					CALL THESE IN CHILD CLASSES
	*******************************************************************/
	// Init the level
	virtual void Init();
	// Update the level (Call this update in all Levels)
	virtual void Update();
	// print out the chars based on fog
	virtual void Render();
	// When Exiting the level
	virtual void Exit();
	// ******************************************************************

private:
	void PrintMap();

protected:
	Fog fog;
};

#endif