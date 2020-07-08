#include "Renderer.h"
#include "PlayableLevels.h"

Renderer::Renderer() : print(nullptr)
{
}

Renderer::~Renderer()
{

}

// Add maps to be rendered onto the screen
void Renderer::Add(char** print, const int& order)
{
	pm->Add(print, order);
}

void Renderer::SetLevel(Level* level)
{
	this->level = level;
	plptr = dynamic_cast<PlayableLevels*>(level);
}

void Renderer::Init()
{
	AllocateMemory();
	DefaultColour();
}

void Renderer::Render()
{
	if (pm->GetSize() <= 0 || plptr->GetIsPaused())
		return;

	char** p_map = pm->GetPrintMap();
	for (int i = 0; i < Console::NewSBSize.Y; ++i)
	{
		char c_array[2] = { p_map[i][0], '\0' };
		strcpy(print, c_array); // Copy from source to destination
		int x = 0;
		int y = i;
		for (int j = 1; j < Console::NewSBSize.X; ++j)
		{
			// To put the first position for printing
			if (x < 0)
				x = j - 1;
			// Consolidate and put it into print (to render onto the screen with colour)
			if (p_map[i][j] == print[0])
			{
				c_array[0] = p_map[i][j];
				strcat(print, c_array); // append the string (add into destination)
				continue;
			}
			Print(print, x, y);
			c_array[0] = p_map[i][j];
			strcpy(print, c_array);
			x = -1;

			if (j <= Console::NewSBSize.X - 1) // at the end of the loop with only 1 character
				x = j; // last index of console size x
		}
		// Have to call another print so that can print from starting of position x
		Print(print, x, y);
	}
}

void Renderer::Exit()
{
	DeallocateMemory();
}

void Renderer::free_memory()
{
	Singleton::free_memory();
}

void Renderer::AllocateMemory()
{
	int size_x = Console::NewSBSize.X;
	print = new char[size_x + 1];
	print[size_x] = '\0';

	pm = new PrintMap;
}

void Renderer::DeallocateMemory()
{
	delete[] print;
	print = nullptr;

	delete pm;
	pm = nullptr;
}

// Set default colour for characters
void Renderer::DefaultColour()
{
	Ice = Colours::FG_CYAN;
	Boulder = Colours::FG_MUSTARD;
	Rock = Colours::FG_GREY;
}

void Renderer::Print(char*& c, const int& x, const int& y)
{
	int console_colour;

	// Set console cursor position
	SetCursorPosition(x, y);

	switch (c[0])
	{
		// Rock
		case (char)177:
		case (char)178:
			console_colour = Rock;
			break;
		// Ice
		case (char)219:
		{
			console_colour = Ice;
			break;
		}
		// Boulder
		case (char)254:
		{
			console_colour = Boulder;
			break;
		}
		default:
		{
			console_colour = Colours::DEFAULT;
			break;
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
	std::cout << c;
}

void Renderer::SetCursorPosition(const int& x, const int& y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}