// Handles Map from .txt file and put them into a 2D Array
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MemoryLeak.h"

class Level;
class LevelManager;
class Map
{
public:
	Map();
	~Map();

	// Returns the map for the camera to "render"
	char **GetMap() const;
	// Get size of x and y
	int GetSizeX() const;
	int GetSizeY() const;
	// Init map from .txt file
	virtual void Init(const char *map =  "", bool duplicate = false, Level* level = nullptr);

private:
	friend class LevelManager;

	// Load map from .txt file and store them into 2D Array
	void LoadMap(bool duplicate, Level* level);
	// Init x and y values
	void InitBorders(std::string res);
	// Creates dynamic 2D array
	void CreateMap(std::vector<std::string> res, bool duplicate, Level* level);
	// Replace and temporary characters to their specific char
	char ReplaceCharacter(char placeHolder, bool duplicate, Level* level, int& blockID, int x = 0, int y = 0);
	// Non Duplicate Replace
	char NonDuplicated(char placeHolder, Level* level, int& blockID, int x, int y);
	// Duplicate Replace
	char Duplicated(char placeHolder);
	// check if string contains specified characters
	bool is_digit(const std::string &c);

	// string containing directory to .txt file
	const char* mapLevel;

protected:
	// Delete Map (using in LevelManager when changing to next scene)
	void Exit();
	// size of map for x and y coords
	int x, y;
	// dyanmic 2D array to store map
	char **map;
};

#endif 