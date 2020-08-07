#include "RendererManager.h"
#include "Console.h"

RendererManager::RendererManager()
{

}

RendererManager::~RendererManager()
{

}

char** RendererManager::GetPrint()
{
	// If prints vector size is more than 0 and have an available dynamic 2D char array, return that instead
	if (prints.size() > 0)
	{
		for (int i = 0; i < prints.size(); ++i)
		{
			char** print = prints[i];
			if (!print[0][0]) // This dynamic 2D char array is not in used
				return prints[i]; // Return this array
		}
	}

	// If not, create new 2D array print
	char** print = nullptr;

	int x = Console::NewSBSize.X;
	int y = Console::NewSBSize.Y;

	print = new char* [y]; // creates row
	for (int i = 0; i < y; ++i)
	{
		print[i] = new char[x + 1]; // create column	
		print[i][x] = '\0';
	}

	// Adding it into the vector
	prints.push_back(print);

	return print;
}

// Called when end or change of level
void RendererManager::Exit()
{
	// Make all print in the prints vector to be null
	int x = Console::NewSBSize.X;
	int y = Console::NewSBSize.Y;
	int index = 0;

	while (index < prints.size())
	{
		// Get memory from the vector
		char** print = prints[index];
		for (int i = 0; i < y; ++i)
		{
			for (int j = 0; j < x; ++j)
				print[i][j] = (char)0;
		}
		++index;
	}
}

void RendererManager::DeletePrints()
{
	int y = Console::NewSBSize.Y;
	while (prints.size() != 0)
	{
		// Get the memory from the vector
		char** print = prints[0];
		for (int i = 0; i < y; ++i)
		{
			delete[] print[i];
			print[i] = nullptr;
		}
		delete[] print;
		print = nullptr;

		// erase the first item from the vector
		prints.erase(prints.begin());
	}
}

void RendererManager::free_memory()
{
	DeletePrints();
	Singleton::free_memory();
}