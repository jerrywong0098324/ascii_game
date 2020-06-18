#include "PlayableLevels.h"
#include "Console.h"

PlayableLevels::PlayableLevels()
{
	pos = &player.GetRefPosition();	
}

PlayableLevels::~PlayableLevels()
{

}

// Init the level
void PlayableLevels::Init()
{
	//InitBuffer();

	y_buffer = 0;
	x_buffer = 0;
	
	const char* pauseMap = "../Game/Map/Default Maps/pause.txt";
	pause.Init(pauseMap);

	Init2DArray();
}

// Update the level
void PlayableLevels::Update()
{
	// if pause, don't update
	if (pause.Update())
		return;

	player.Update();
	SideScroll();
}

// print out the chars
void PlayableLevels::Render()
{
	// if paused, print option menu then return
	if (pause.GetIsPaused())
	{
		pause.Render();
		return;
	}

	PrintMap();
}

// When Exiting the level
void PlayableLevels::Exit()
{
	pause.ExitP();
	Delete2DArray();
}

// For sidescrolling
void PlayableLevels::SideScroll()
{
	ScrollRight();
	ScrollLeft();
	ScrollUp();
	ScrollDown();
}

int PlayableLevels::ScrollRightLimit(int multiplier, int divider)
{
	return Console::NewSBSize.X - Console::NewSBSize.X * multiplier / divider + x_buffer;
}

int PlayableLevels::ScrollLeftLimit(int multiplier, int divider)
{
	return Console::NewSBSize.X * multiplier / divider + x_buffer;
}

int PlayableLevels::ScrollUpLimit(int multiplier, int divider)
{
	return Console::NewSBSize.Y * multiplier / divider + y_buffer;;
}

int PlayableLevels::ScrollDownLimit(int multiplier, int divider)
{
	return Console::NewSBSize.Y - Console::NewSBSize.Y * multiplier / divider + y_buffer;
}

void PlayableLevels::ScrollRight()
{
	// unable to scroll right further (end of the map)
	if (x_buffer + Console::NewSBSize.X >= map.GetSizeX())
		return;

	// Only can scroll right at 1/3 (right side) of the map
	if (pos->x >= ScrollRightLimit(1, 4))
		++x_buffer; // scrolling right
}

void PlayableLevels::ScrollLeft()
{
	// 0 is at the border of left side of map
	if (x_buffer <= 0)
		return;

	// Only can scroll right at 1/3 (left side) of the map
	if (pos->x <= ScrollLeftLimit(1, 4))
		--x_buffer; // scrolling right
}

void PlayableLevels::ScrollUp()
{
	// at the top
	if (y_buffer <= 0)
		return;

	// Only can scroll right at 1/3 way of top of the map
	if (pos->y <= ScrollUpLimit(1, 4))
		--y_buffer; // scrolling right
}

void PlayableLevels::ScrollDown()
{
	// unable to scroll down further
	if (y_buffer + Console::NewSBSize.Y >= map.GetSizeY())
		return;

	// Only can scroll right at 1/3 (right side) of the map
	if (pos->y >= ScrollDownLimit(1, 4))
		++y_buffer; // scrolling right
}

// init buffer based on player's pos
void PlayableLevels::InitBuffer()
{
	// TODO: rework formula for x and y buffer upon load
	x_buffer = pos->x * 0.5f;
	y_buffer = pos->y * 0.5f;
}

void PlayableLevels::PrintMap()
{
	// Put the map into print's 2d dynamic array
	for (int i = y_buffer; i < YLimit(); ++i)
	{
		// printing the map one character at a time
		for (int j = x_buffer; j < XLimit(); ++j)
			print[i - y_buffer][j - x_buffer] = map.GetMap()[i][j];
	}

	int y = Console::NewSBSize.Y; // Console size
	// Print the map
	for (int i = 0; i < y; ++i)
	{
		const char* row = *(print + i);
		std::printf("%s", row);
	}
}

int PlayableLevels::XLimit()
{
	int limit = x_buffer + Console::NewSBSize.X;
	if (limit > map.GetSizeX()) // safe check
		limit = map.GetSizeX();
	return limit;
}

int PlayableLevels::YLimit()
{
	int limit = y_buffer + Console::NewSBSize.Y;
	if (limit > map.GetSizeY()) // safe check
		limit = map.GetSizeY();
	return limit;
}

void PlayableLevels::Init2DArray()
{
	int x = Console::NewSBSize.X;
	int y = Console::NewSBSize.Y;

	print = new char* [y]; // creates row
	for (int i = 0; i < y; ++i)
	{
		print[i] = new char[x + 1]; // create column	
		print[i][x] = '\0';
	}
}

void PlayableLevels::Delete2DArray()
{
	if (!print) // memory successfully deallocated already
		return;

	int x = Console::NewSBSize.X;
	int y = Console::NewSBSize.Y;
	for (int i = 0; i < y; ++i)
	{
		delete[] print[i];
		print[i] = nullptr;
	}
	delete[] print;
	print = nullptr;
}