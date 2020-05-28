// LevelManager class to handle changing of level, from Menu to Game to Custom Map
#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Singleton.h"
#include "Map.h"

class LevelManager
{
public:

private:
	// map level stores all the default map (maps created by me)
	std::vector<std::string> mapLevels;
};

#endif 