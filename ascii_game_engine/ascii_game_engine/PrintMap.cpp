#include "PrintMap.h"
#include <algorithm>

PrintMap::PrintMap()
{

}

PrintMap::~PrintMap()
{

}

// Adds map to print
void PrintMap::Add(char** print, const int& order)
{
	std::pair<int, char**> temp(order, print);
	// Add into vector
	print_maps.push_back(temp); 
	// Sort print maps based on order (ascending order)
	std::sort(print_maps.begin(), print_maps.end());
}

// Returns sorted map, ready to be rendered onto the screen
char** PrintMap::GetPrintMap() const
{
	// If there's a better way to improve on the current code, please do it
	// Idea for this: Put each layer of character onto the print

	char** print = print_maps[0].second;
	char ignore = (char)250;
	for (int i = 0; i < Console::NewSBSize.Y; ++i)
	{
		int index = 0;
		for (int j = 0; j < Console::NewSBSize.X; ++j)
		{
			while (index < print_maps.size())
			{
				char c = print_maps[index].second[i][j];
				// (char)250 indicates to use previous order's map which is not (char)250
				if (c == ignore && index > 0)
				{
					for (int k = index - 1; k > 0; --k)
					{
						c = print_maps[k].second[i][j];
						if (c != ignore)
							break;
					}		
				}
				print[i][j] = c;
				++index;
			}
		}
	}
	return print;
}

// Return size of vector
size_t PrintMap::GetSize() const
{
	return print_maps.size();
}