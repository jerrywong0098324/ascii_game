#include "Renderer.h"
#include "PlayableLevels.h"
#include "Ice.h"

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

// Add special cases rendering to be rendered over the original
void Renderer::AddOverlap(const OverlapPrint& print)
{
	ol_prints.push_back(print);
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
	RenderNormal();
	//RenderOverlap();
}

// Normal rendering
void Renderer::RenderNormal()
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
		Vector2 pos(x, y);
		for (int j = 1; j < Console::NewSBSize.X; ++j)
		{
			// To put the first position for printing
			if (x < 0)
				x = j - 1;
			// Consolidate and put it into print (to render onto the screen with colour)
			else if (p_map[i][j] == print[0])
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

// Special render conditions, Eg: Ice
void Renderer::RenderOverlap()
{
	if (ol_prints.size() <= 0 || plptr->GetIsPaused())
		return;

	while (ol_prints.size() > 0)
	{
		char* cp = ol_prints[0].GetString();
		Print(cp, ol_prints[0].GetPosition().x, ol_prints[0].GetPosition().y, ol_prints[0].GetColour());
		// decrease the amount of prints in the vector
		ol_prints.erase(ol_prints.begin());
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

	temp = new char[size_x + 1];
	temp[size_x] = '\0';

	pm = new PrintMap;
}

void Renderer::DeallocateMemory()
{
	delete[] print;
	print = nullptr;

	delete[] temp;
	temp = nullptr;

	delete pm;
	pm = nullptr;

	ol_prints.clear();
}

// Set default colour for characters
void Renderer::DefaultColour()
{
	ice = Colours::FG_CYAN;
	boulder = Colours::FG_MUSTARD;
	rock = Colours::FG_GREY;
}

void Renderer::Print(char*& str, const int& x, const int& y)
{
	int console_colour = Colours::DEFAULT;

	// Set console cursor position
	SetCursorPosition(x, y);

	console_colour = GetColours(str[0]);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
	std::cout << str;
}

void Renderer::Print(char*& str, const int& x, const int& y, const int& colours)
{
	// Set console cursor position
	SetCursorPosition(x, y);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colours);
	std::cout << str;
}

void Renderer::SetCursorPosition(const int& x, const int& y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//// Get the first ice block's id
//Vector2 pos(x, y);
//int id = plptr->GetBlockID(pos);
//int index = 0; // use to add to position
//// if nothing on top of ice
//console_colour = ice;
//// Prints out all the ice first
//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
//std::cout << str;
//const char* str2 = str;
//// if something on top of ice, bg becomes cyan, fg_be whatever it is and print out the character on top
//while (str2[index] != '\0') // Searching through the ice blocks to find if there's anything other characters on it
//{
//	Ice* iptr = dynamic_cast<Ice*>(plptr->GetBlock(id + index));
//	char c = iptr->GetBlockOnIce();
//	SetCursorPosition(pos.x + index, pos.y);
//
//	// changes the console colour
//	switch (c)
//	{
//	case (char)254: // Boulder
//	{
//		console_colour = boulder | Colours::BG_CYAN;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
//		std::cout << c;
//		break;
//	}
//	default: // Could be player
//	{
//		console_colour = Colours::DEFAULT | Colours::BG_CYAN;
//		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), console_colour);
//		std::cout << c;
//		break;
//	}
//	}
//
//	++index; // increment the index to loop through the entire str
//}
//return;