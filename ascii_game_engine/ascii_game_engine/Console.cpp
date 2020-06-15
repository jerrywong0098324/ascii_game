#include "Console.h"

COORD Console::NewSBSize;

Console::Console()
{

}

Console::~Console()
{

}

void Console::CreateConsole(int width, int height)
{
	// Changes the size of console window
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, width, height, TRUE);

	// Changes console buffer size (how much can be scroll etc)
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO SBInfo;	
	int Status;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hOut, &SBInfo);
	Console::NewSBSize.X = SBInfo.dwSize.X;
	Console::NewSBSize.Y = SBInfo.dwSize.Y;

	// Sets the buffer size. If doesn't work, change properties (buffer size) of the console manually by executing the program first
	Status = SetConsoleScreenBufferSize(hOut, Console::NewSBSize);
	if (Status == 0)
	{
		Status = GetLastError();
		std::cout << "SetConsoleScreenBufferSize() failed! Reason : " << Status << std::endl;
		exit(Status);
	}

	// Removing console cursor
	CONSOLE_CURSOR_INFO ci;
	ci.dwSize = 1;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ci);

	// Debugging process
	//GetConsoleScreenBufferInfo(hOut, &SBInfo);
	//std::cout << "Screen Buffer Size : ";
	//std::cout << SBInfo.dwSize.X << " x ";
	//std::cout << SBInfo.dwSize.Y << std::endl;
}

// Reset the cursor position
void Console::ClearScreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Prints out line of empty string to "clear" the screen
void Console::ClearBox()
{
	HANDLE hOut;
	COORD Position;
	DWORD Written;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	FillConsoleOutputCharacter(hOut, ' ', INT32_MAX, Position, &Written);

	SetConsoleCursorPosition(hOut, Position);
}