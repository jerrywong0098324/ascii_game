// Handles Map from .txt file and put them into a 2D Array
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Map
{
public:
	Map();
	~Map();

	// Returns the map for the camera to "render"
	char **GetMap();
	// Init map from .txt file
	void Init(std::string mapLevel = "");

private:
	// Load map from .txt file and store them into 2D Array
	void LoadMap();
	// Open files
	void OpenFile(std::vector<std::string> &res);
	// Init x and y values
	void InitBorders(std::string res);
	// Creates dynamic 2D array
	void CreateMap(std::vector<std::string> res);
	// Delete Map (using in LevelManager when changing to next scene)
	// check if string contains specified characters
	bool is_digit(const std::string &c);

	// string containing directory to .txt file
	std::string mapLevel;

	// size of map for x and y coords
	int x, y;
	// dyanmic 2D array to store map
	char **map;
};

#endif 