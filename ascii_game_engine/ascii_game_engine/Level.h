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

	Map GetMap() const
	{
		return map;
	}

	Map GetDuplicatedMap() const
	{
		return duplicate_map;
	}

	// change the characters of the map only
	void SetMap(const int& x, const int& y, const char& c)
	{
		map.GetMap()[y][x] = c;
	}

	// change the characters of the map and duplicate map
	void SetBothMap(const int& x, const int& y, const char& c)
	{
		map.GetMap()[y][x] = c;
		duplicate_map.GetMap()[y][x] = c;
	}

	void SetDuplicateMapName(const char* map_name)
	{
		duplicate_map.Init(map_name, true);
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
	// ******************************************************************
	Map duplicate_map; // duplicate of the playing map, won't be able to change any data of the map here (making it a const variable at runtime)
	// ******************************************************************
};

#endif