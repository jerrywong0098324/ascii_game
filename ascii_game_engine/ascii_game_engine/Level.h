// Abstract class to handle level
#ifndef	LEVEL_H
#define LEVEL_H

#include "Map.h"

class Level
{
public:
	// mapLevel -> file directory of the map
	Level(std::string mapLevel) : currMap(mapLevel)
	{

	};
	virtual ~Level() = 0;

	virtual char **GetMap()
	{
		return currMap.GetMap();
	}
	// When Exiting the level
	void Exit() {};

protected:
	// Map to handle the current map level
	Map currMap;
	// Sound to handle playing music?
};

#endif