#include "Map.h"

Map::Map(std::string mapLevel) : mapLevel(mapLevel)
{
	LoadMap();

}

Map::~Map()
{
	for (int i = 0; i < y; ++i)
	{
		delete[] * (map + i);
		*(map + i) = nullptr;
	}
	delete[] map;
	map = nullptr;
}

char** Map::GetMap()
{
	return map;
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
		map[i] = new char[x + 1]; // create column	

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			map[i][j] = res[i + 1][j];
			if (j + 1 >= x)
				map[i][j + 1] = '\0';
		}
	}
}

// check if string contains specified characters
bool Map::is_digit(const std::string& c)
{
	return c.find_first_not_of("0123456789") == c.npos;
}