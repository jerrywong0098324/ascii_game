#include "FogLevels.h"
#include "Console.h"

FogLevels::FogLevels()
{

}

FogLevels::~FogLevels()
{

}

// Init the level
void FogLevels::Init()
{
	PlayableLevels::Init(); // updates pause and buffers
	fog.Init(map, player.GetRefPosition());
}

// Update the level (Call this update in all Levels)
void FogLevels::Update()
{
	PlayableLevels::Update(); // updates the player and side scrolling
	if (pause.GetIsPaused()) // paused, dont update
		return;

	fog.Update();
}

// print out the chars based on fog
void FogLevels::Render()
{
	// if paused, print option menu then return
	if (pause.GetIsPaused())
	{
		pause.Render();
		return;
	}

	// my own print map here
	PrintMap();
}

// When Exiting the level
void FogLevels::Exit()
{
	PlayableLevels::Exit();
	fog.Exit();
}

void FogLevels::PrintMap()
{
	for (int i = y_buffer; i < YLimit(); ++i)
	{
		for (int j = x_buffer; j < XLimit(); ++j)
		{
			if (fog.GetFog()[i][j]) // there's fog here
				print[i - y_buffer][j - x_buffer] = ' '; // empty space
			else // no fog here
				print[i - y_buffer][j - x_buffer] = map.GetMap()[i][j]; // sees the map
		}
	}

	int y = Console::NewSBSize.Y; // Console size
	// Print the map
	for (int i = 0; i < y; ++i)
	{
		const char* row = *(print + i);
		std::printf("%s", row);
	}
}