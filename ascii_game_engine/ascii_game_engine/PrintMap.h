// This stores a vector of 2D dynamic array, to be printed onto the map
#ifndef PRINT_MAP_H
#define PRINT_MAP_H

#include <vector>
#include "Console.h"

class PrintMap
{
public:
	PrintMap();
	~PrintMap();

	// Adds map to print
	void Add(char** print, const int& order);
	// Returns sorted map, ready to be rendered onto the screen
	char** GetPrintMap() const;
	// Return size of vector
	size_t GetSize() const;

private:
	std::vector<std::pair<int, char**>> print_maps;
};

#endif