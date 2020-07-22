#include "Map.h"
#include "Game.h"
#include "FileManager.h"
#include "Rock.h"
#include "Ice.h"
#include "Boulder.h"

Map::Map() : x(0), y(0), map(nullptr)
{

}

Map::~Map()
{
	//Exit();
}

char** Map::GetMap() const
{
	return map;
}

// Returns specific character from dynamic 2D array
char Map::GetCharacter(const int& x, const int& y)
{
	return map[y][x];
}

// Set specific character into dynamic 2D array
void Map::SetCharacter(const int& x, const int& y, const char& c)
{
	map[y][x] = c;
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
void Map::CreateMap(std::vector<std::string> res, bool duplicate, Level* level)
{
	map = new char* [y]; // creates row
	for (int i = 0; i < y; ++i)
	{
		map[i] = new char[x + 1]; // create column	
		map[i][x] = '\0';
	}

	int sum = Game::GetInstance()->GetTotalReplace();
	char* list = Game::GetInstance()->GetReplaceList();
	int blockID = 0; // ID of block

	// storing map from .txt file into 2D dynamic array
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			char c = res[i + 1][j];

			// replacing all place holder characters to their respective chars in game
			for (int k = 0; k < sum; ++k)
			{
				if (c == list[k])
				{
					c = ReplaceCharacter(list[k], duplicate, level, blockID, j, i);
					break;
				}
			}

			map[i][j] = c;
		}
	}
}

// Replace and temporary characters to their specific char
char Map::ReplaceCharacter(char placeHolder, bool duplicate, Level* level, int& blockID, int x, int y)
{
	if (!duplicate)
		return NonDuplicated(placeHolder, level, blockID, x, y);
	else if (duplicate)
		return Duplicated(placeHolder);
}

// Non Duplicate Replace
char Map::NonDuplicated(char placeHolder, Level* level, int& blockID, int x, int y)
{
	char c = (char)0; // null char(?)
	PlayableLevels* plptr;
	Vector2 pos(x, y);

	switch (placeHolder)
	{
		case '+': // empty block
		{
			c = ' ';
			break;
		}
		case '!':
		{
			c = (char)255;
			break;
		}
		case '~': // rock
		{
			c = (char)178;
			plptr = dynamic_cast<PlayableLevels*>(level); // PlabaleLevels pointer

			Rock* rptr = new Rock(blockID);
			rptr->Init(); // init rocks
			rptr->SetBlockType("Rock");
			rptr->SetPosition(pos); // position of rock

			plptr->AddBlock(rptr); // add into level

			++blockID;
			break;
		}
		case '`': // ice
		{
			c = (char)219;
			plptr = dynamic_cast<PlayableLevels*>(level); // PlabaleLevels pointer

			Player* pptr = &plptr->GetRefPlayer(); // Player pointer

			Ice* iptr = new Ice(blockID);
			iptr->Init(pptr, level); // inits ice
			iptr->SetBlockType("Ice");
			iptr->SetPosition(pos); // position of ice

			plptr->AddBlock(iptr); // add into level to update

			++blockID;
			break;
		}
		case '{': // boulder
		{
			c = (char)254;
			plptr = dynamic_cast<PlayableLevels*>(level); // PlabaleLevels pointer

			Player* pptr = &plptr->GetRefPlayer(); // Player pointer

			Boulder* bptr = new Boulder(blockID);
			bptr->SetPosition(pos); // position of the boulder
			bptr->SetBlockType("Boulder");
			bptr->Init(pptr, level); // inits boulder

			plptr->AddBlock(bptr); // add into level to update

			++blockID;
			break;
		}
	}

	return c;
}

// Duplicate Replace
char Map::Duplicated(char placeHolder)
{
	char c = (char)0; // null char

	switch (placeHolder)
	{
		case '+': // empty block
		{
			c = ' ';
			break;
		}
		case '!':
		{
			c = (char)255;
			break;
		}
		case '~': // rock
		{
			c = (char)178;
			break;
		}
		case '`': // ice
		{
			c = (char)219;
			break;
		}
		case '{': // boulder
		{
			c = (char)254;
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