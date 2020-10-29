#include "Map.h"
#include "Game.h"
#include "FileManager.h"

Map::Map() : x(0), y(0), map(nullptr)
{

}

Map::~Map()
{
	//Exit();
}

TextBox** Map::GetMap() const
{
	return map;
}

// Returns specific character from dynamic 2D array
char Map::GetCharacter(const int& x, const int& y)
{
	return map[y][x].GetCharacter();
}

// Return id from dynamic 2D array
TbxID Map::GetID(const int& x, const int& y)
{
	return map[y][x].GetID();
}

// Set specific character into dynamic 2D array
void Map::SetCharacter(const int& x, const int& y, const char& c)
{
	map[y][x].SetCharacter(c);
}

// Set ID based on char
void Map::SetID(const int& x, const int& y, const char& c)
{
	map[y][x].SetID(c);
}

// Set ID based on TbxID itself
void Map::SetID(const int& x, const int& y, const TbxID& id)
{
	map[y][x].SetID(id);
}

// Get size of x and y
int Map::GetSizeX() const
{
	return x;
}

int Map::GetSizeY() const
{
	return y;
}

// Init map from .txt file
void Map::Init(const char *mapLevel, bool duplicate, Level* level)
{
	this->mapLevel = mapLevel;
	LoadMap(duplicate, level);
}

// Delete Map (using in LevelManager when changing to next scene)
void Map::Exit()
{
	if (!map) // memory successfully deallocated already
		return;

	for (int i = 0; i < y; ++i)
	{
		delete[] map[i];
		map[i] = nullptr;
	}
	delete[] map;
	map = nullptr;
}

// Load map from .txt file and store them into 2D Array
void Map::LoadMap(bool duplicate, Level* level)
{
	std::vector<std::string> res = FileManager::LoadFile(mapLevel); // result of strings in .txt file

	// get x and y value
	InitBorders(res[0]);
	// initialise 2D dynamic array
	CreateMap(res, duplicate, level);
}

// Init x and y values
void Map::InitBorders(std::string res)
{
	std::string num;
	// First line of .txt file -> Stores size for x and y
	for (int i = 0; i < res.length(); ++i) // extract value for x
	{
		std::string ch(1, res[i]);
		if (is_digit(ch))
			num += ch;
		// finish extracting value to x
		else if (ch == ",")
			break;
	}

	x = std::stoi(num);
	num.clear(); // empty the string

	// extract value for y from the back
	for (int i = res.length() - 1; i >= 0; --i)
	{
		std::string ch(1, res[i]);
		if (is_digit(ch))
			num.insert(num.begin(), ch[0]);
		else if (ch == "=")
			break;
	}

	y = std::stoi(num);
	num.clear();
}

// Creates dynamic 2D array map
void Map::CreateMap(std::vector<std::string> res, const bool& duplicate, Level* level)
{
	map = new TextBox* [y]; // creates row
	for (int i = 0; i < y; ++i)
		map[i] = new TextBox[x]; // create column

	int sum = Game::GetInstance()->GetTotalReplace();
	char* list = Game::GetInstance()->GetReplaceList();
	int blockID = 0; // ID of block

	// storing map from .txt file into 2D dynamic array
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			char c = res[i + 1][j];

			map[i][j].SetID(TbxID::INVALID);
			// replacing all place holder characters to their respective chars in game
			for (int k = 0; k < sum; ++k)
			{
				if (c == list[k])
				{
					c = ReplaceCharacter(list[k], duplicate, level, blockID, j, i);
					break;
				}
			}

			map[i][j].SetCharacter(c);
		}
	}
}

// Replace and temporary characters to their specific char
char Map::ReplaceCharacter(const char& placeHolder, const bool& duplicate, Level* level, int& blockID, const int& x, const int& y)
{
	if (!duplicate)
		return NonDuplicated(placeHolder, level, blockID, x, y);
	else if (duplicate)
		return Duplicated(placeHolder, x, y);
}

// Non Duplicate Replace
char Map::NonDuplicated(const char& placeHolder, Level* level, int& blockID, const int& x, const int& y)
{
	char c = (char)0; // null char(?)
	PlayableLevels* plptr;
	Vector2 pos(x, y);

	switch (placeHolder)
	{
		case '+': // empty block
		{
			c = ' ';
			map[y][x].SetID(TbxID::EMPTY_SPACE);
			break;
		}
	}

	return c;
}

// Duplicate Replace
char Map::Duplicated(const char& placeHolder, const int& x, const int& y)
{
	char c = (char)0; // null char

	switch (placeHolder)
	{
		case '+': // empty block
		{
			c = ' ';
			map[y][x].SetID(TbxID::EMPTY_SPACE);
			break;
		}
	}

	return c;
}

// check if string contains specified characters
bool Map::is_digit(const std::string& c)
{
	return c.find_first_not_of("0123456789") == c.npos;
}