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

char RendererManager::GetIgnore() const
{
	return (char)250;
}

void RendererManager::DeletePrints()
{
	int x = Console::NewSBSize.X;
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