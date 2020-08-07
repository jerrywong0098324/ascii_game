// Handles Map from .txt file and put them into a 2D Array
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MemoryLeak.h"
#include "TextBox.h"

class Level;
class LevelManager;
class Map
{
public:
	Map();
	~Map();

	// Returns the map for the camera to "render"
	TextBox** GetMap() const;
	// Returns specific character from dynamic 2D array
	char GetCharacter(const int& x, const int& y);
	// Return id from dynamic 2D array
	TbxID GetID(const int& x, const int& y);
	// Set specific character into dynamic 2D array
	void SetCharacter(const int& x, const int& y, const char& c);
	// Set ID based on char
	void SetID(const int& x, const int& y, const char& c);
	// Set ID based on TbxID itself
	void SetID(const int& x, const int& y, const TbxID& id);
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
	void CreateMap(std::vector<std::string> res, const bool& duplicate, Level* level);
	// Replace and temporary characters to their specific char
	char ReplaceCharacter(const char& placeHolder, const bool& duplicate, Level* level, int& blockID, const int& x = 0, const int& y = 0);
	// Non Duplicate Replace
	char NonDuplicated(const char& placeHolder, Level* level, int& blockID, const int& x, const int& y);
	// Duplicate Replace
	char Duplicated(const char& placeHolder, const int& x, const int& y);
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
	TextBox** map;
};

#endif 