#include "Map.h"

Map::Map() : x(0), y(0), map(nullptr)
{
	//LoadMap();
}

Map::~Map()
{

}

char** Map::GetMap() const
{
	return map;
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
void Map::Init(const char *mapLevel)
{
	this->mapLevel = mapLevel;
	LoadMap();
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
void Map::LoadMap()
{
	std::vector<std::string> res; // result of strings in .txt file

	// open .txt file and store results into vector
	OpenFile(res);
	// get x and y value
	InitBorders(res[0]);
	// initialise 2D dynamic array
	CreateMap(res);
}

// Open files
void Map::OpenFile(std::vector<std::string>& res)
{
	std::string items; // use to store string per line from .txt file
	std::ifstream inFile(mapLevel); // Input file

	// Check for any errors -> corrupted files, wrong file name etc
	if (inFile.fail())
	{
		std::cerr << "Unable to open file: " << mapLevel << std::endl;
		exit(1);
		//return; // just return
	}

	// Loop through till the end of file
	while (!inFile.eof())
	{
		inFile >> items;
		res.push_back(items);
	}
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
void Map::CreateMap(std::vector<std::string> res)
{
	map = new char* [y]; // creates row
	for (int i = 0; i < y; ++i)
	{
		map[i] = new char[x + 1]; // create column	
		map[i][x] = '\0';
	}

	// storing map from .txt file into 2D dynamic array
	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			char c = res[i + 1][j];
			if (c == '+') // replacing '+' to become empty spaces
				c = ' ';
			map[i][j] = c;
		}
	}
}

// check if string contains specified characters
bool Map::is_digit(const std::string& c)
{
	return c.find_first_not_of("0123456789") == c.npos;
}