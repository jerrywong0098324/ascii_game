#include "PlayableLevels.h"
#include "Console.h"

PlayableLevels::PlayableLevels() : x_buffer (0), y_buffer(0)
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
	
	const char* pauseMap = "../Game/Map/Default Maps/pause.txt";
	pause.Init(pauseMap);
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
}

// For sidescrolling
void PlayableLevels::SideScroll()
{
	ScrollRight();
	ScrollLeft();
	ScrollUp();
	ScrollDown();
}

int PlayableLevels::ScrollLimitX(int multiplier, int divider)
{
	return Console::NewSBSize.X - Console::NewSBSize.X * multiplier / divider + x_buffer;
}

int PlayableLevels::ScrollLimitY(int multiplier, int divider)
{
	return Console::NewSBSize.Y - Console::NewSBSize.Y * multiplier / divider + y_buffer;
}

void PlayableLevels::ScrollRight()
{
	// unable to scroll right further (end of the map)
	if (x_buffer + Console::NewSBSize.X >= map.GetSizeX())
		return;

	// Only can scroll right at 1/3 (right side) of the map
	if (pos->x >= ScrollLimitX(1, 3))
		++x_buffer; // scrolling right
}

void PlayableLevels::ScrollLeft()
{
	// 0 is at the border of left side of map
	if (x_buffer <= 0)
		return;

	// Only can scroll right at 2/3 (left side) of the map
	if (pos->x <= ScrollLimitX(2, 3))
		--x_buffer; // scrolling right
}

void PlayableLevels::ScrollUp()
{
	// at the top
	if (y_buffer <= 0)
		return;

	// Only can scroll right at 2/3 way of top of the map
	if (pos->y <= ScrollLimitY(2, 3))
		--y_buffer; // scrolling right
}

void PlayableLevels::ScrollDown()
{
	// unable to scroll down further
	if (y_buffer + Console::NewSBSize.Y >= map.GetSizeY())
		return;

	// Only can scroll right at 1/3 (right side) of the map
	if (pos->y >= ScrollLimitY(1, 3))
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
	for (int i = y_buffer; i < YLimit(); ++i)
	{
		// printing the map one character at a time
		for (int j = x_buffer; j < XLimit(); ++j)
			std::cout << map.GetMap()[i][j];
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