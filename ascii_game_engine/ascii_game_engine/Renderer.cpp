#include "Renderer.h"
#include "Console.h"
#include "PlayableLevels.h"
#include "Ice.h"

Renderer::Renderer() : print(nullptr)
{
}

Renderer::~Renderer()
{

}

// Replace the current pt data to be used for rendering
void Renderer::Add(const int& x, const int& y, const Print& pt)
{
	Print prt = this->pt[y][x];
	// overlap if pt's (passed in varible) order is greater
	if (prt.GetOrder() > pt.GetOrder())
		return;
	this->pt[y][x] = pt;
}

void Renderer::Add(const int& x, const int& y, const int& order, const int& colour, char c)
{
	Print prt;
	prt.SetOrder(order);
	prt.SetColour(colour);
	prt.SetCharacter(c);
	// overlap if order (passed in variable) is greater
	if (this->pt[y][x].GetOrder() > order)
		return;
	this->pt[y][x] = prt;
}

void Renderer::SetLevel(Level* level)
{
	this->level = level;
	plptr = dynamic_cast<PlayableLevels*>(level);
}

// Get Colours based on the char
int Renderer::GetColours(const char& c)
{
	int console_colour = Colours::BLACK | Colours::FG_WHITE;
	switch (c)
	{
			// Rock
		case (char)177:
		case (char)178:
			console_colour = rock;
			break;
			// Ice
		case (char)219:
		{
			console_colour = ice;
			break;
		}
		// Boulder
		case (char)254:
		{
			console_colour = boulder;
			break;
		}
		default:
		{
			console_colour = Colours::BLACK | Colours::FG_WHITE;
			break;
		}
	}
	return console_colour;
}

// Get temp string
char* Renderer::GetTemporaryString() const
{
	return temp;
}

void Renderer::Init()
{
	AllocateMemory();
	DefaultColour();
}

void Renderer::Render()
{
	PrintMap();
}

void Renderer::Exit()
{
	RendererManager::GetInstance()->Exit();
	DeallocateMemory();
}

void Renderer::free_memory()
{
	Singleton::free_memory();
}

void Renderer::AllocateMemory()
{
	int x = Console::NewSBSize.X;
	int y = Console::NewSBSize.Y;

	print = new char[x + 1];
	print[x] = '\0';

	temp = new char[x + 1];
	temp[x] = '\0';

	//pm = new PrintMap;
	pt = new Print*[y];
	for (int i = 0; i < y; ++i)
		pt[i] = new Print[x];
}

void Renderer::DeallocateMemory()
{
	delete[] print;
	print = nullptr;

	delete[] temp;
	temp = nullptr;

	// if pt is initialized, then deallocate data
	if (pt)
	{
		int y = Console::NewSBSize.Y;
		for (int i = 0; i < y; ++i)
		{
			delete[] pt[i];
			pt[i] = nullptr;
		}
		delete[] pt;
		pt = nullptr;
	}
}

// Set default colour for characters
void Renderer::DefaultColour()
{
	ice = Colours::FG_CYAN;
	boulder = Colours::FG_MUSTARD;
	rock = Colours::FG_GREY;
}

void Renderer::PrintMap()
{
	if (!plptr || plptr->GetIsPaused())
		return;

	for (int i = 0; i < Console::NewSBSize.Y; ++i)
	{
		char c_array[2] = { pt[i][0].GetCharacter(), '\0' };
		strcpy(print, c_array); // Copy from source to destination
		int x = 0;
		int y = i;
		Vector2 pos(x, y);

		for (int j = 1; j < Console::NewSBSize.X; ++j)
		{
			char c = pt[i][j].GetCharacter();

			// To put the first position for printing
			if (x < 0)
				x = j - 1;
			// Consolidate and put it into print (to render onto the screen with colour)
			else if (pt[i][j].GetCharacter() == print[0])
			{
				c_array[0] = pt[i][j].GetCharacter();
				strcat(print, c_array); // append the string (add into destination)
				continue;
			}
 			PrintMap(print, x, y, pt[i][j - 1].GetColour());
			c_array[0] = pt[i][j].GetCharacter(); // Get current char for the next loop
			strcpy(print, c_array);
			x = -1;

			if (j <= Console::NewSBSize.X - 1) // at the end of the loop with only 1 character
				x = j; // last index of console size x
		}
		// Have to call another print so that can print from starting of position x
		PrintMap(print, x, y, pt[y][x].GetColour());
	}

	ResetPrint();
}

void Renderer::PrintMap(char*& str, const int& x, const int& y)
{
	int console_colour = Colours::DEFAULT;

	// Set console cursor position
	SetCursorPosition(x, y);

	console_colour = GetColours(str[0]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
	std::cout << str;
}

void Renderer::PrintMap(char*& str, const int& x, const int& y, const int& colours)
{
	int console_colour = colours;

	// Set console cursor position
	SetCursorPosition(x, y);

	if(colours == Colours::TBC)
		console_colour = GetColours(str[0]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
	std::cout << str;
}

void Renderer::SetCursorPosition(const int& x, const int& y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Renderer::ResetPrint()
{
	for (int i = 0; i < Console::NewSBSize.Y; ++i)
	{
		for (int j = 0; j < Console::NewSBSize.X; ++j)
			pt[i][j].Reset();
	}
}