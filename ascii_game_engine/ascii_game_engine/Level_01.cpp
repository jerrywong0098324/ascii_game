#include "Level_01.h"

Level_01::Level_01()
{

}

Level_01::~Level_01()
{

}

// Init the level
void Level_01::Init()
{
	const char *mapLevel = "../Game/Map/Default Maps/level_01.txt";
	map.Init(mapLevel);

	// *******************************************************	
	player.Init(map, std::move(Vector2(1, 1)));

	// *******************************************************

	PlayableLevels::Init();
	GameStateManager::GetInstance()->SetBothStates(GameState::LEVEL_01);
}

// Update the level
void Level_01::Update()
{
	PlayableLevels::Update();
	// if paused, don't update
}

// print out the chars
void Level_01::Render()
{
	PlayableLevels::Render();
}

// When Exiting the level
void Level_01::Exit()
{
	// Call LevelManager to change to next map
}