#include "PrintMap.h"
#include <algorithm>

PrintMap::PrintMap()
{

}

PrintMap::~PrintMap()
{

}

// Adds map to print
void PrintMap::Add(const char** print, const int& order)
{
	std::pair<int, const char**> temp(order, print);
	// Add into vector
	print_maps.push_back(temp); 
	// Sort print maps based on order (ascending order)
	std::sort(print_maps.begin(), print_maps.end());
}

// Returns sorted map, ready to be rendered onto the screen
const char** PrintMap::GetPrintMap() const
{
	char** print;
	while ()
	{

	}
}