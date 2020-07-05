// This stores a vector of 2D dynamic array, to be printed onto the map
#ifndef PRINT_MAP_H
#define PRINT_MAP_H

#include <vector>

class PrintMap
{
public:
	PrintMap();
	~PrintMap();

	// Adds map to print
	void Add(const char** print, const int& order);
	// Returns sorted map, ready to be rendered onto the screen
	const char** GetPrintMap() const;

private:
	std::vector<std::pair<int, const char**>> print_maps;
};

#endif