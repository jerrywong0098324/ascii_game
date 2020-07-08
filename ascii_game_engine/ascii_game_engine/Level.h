// Abstract class to handle level
#ifndef	LEVEL_H
#define LEVEL_H

#include "Map.h"
#include "Audio.h"
#include "Timer.h"
#include "Renderer.h"
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

	// Get specific character from map at x, y pos
	char GetCharacter(const int& x, const int& y)
	{
		return map.GetCharacter(x, y);
	}

	// Change the characters of the map at x, y pos
	void SetMap(const int& x, const int& y, const char& c)
	{
		map.SetCharacter(x, y, c);
	}

	// Change the characters of the map and duplicate map
	void SetBothMap(const int& x, const int& y, const char& c)
	{
		map.SetCharacter(x, y, c);
		duplicate_map.SetCharacter(x, y, c);
	}

	// Correct the map by putting duplicate map over map
	void CorrectMap(const int& x, const int& y)
	{
		char c = duplicate_map.GetCharacter(x, y);
		map.SetCharacter(x, y, c);
	}

	void SetDuplicateMapName(const char* map_name)
	{
		duplicate_map.Init(map_name, true);
	}

	bool WithinMap(const int& x, const int& y)
	{
		return x < map.GetSizeX() && x >= 0 && y < map.GetSizeY() && y >= 0;
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
	Map duplicate_map; // duplicate of the playing map, won't be able to change any data of the map here unneccessarily
	// ******************************************************************
};

#endif