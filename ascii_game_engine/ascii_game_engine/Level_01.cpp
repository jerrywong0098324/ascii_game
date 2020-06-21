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
	map.Init(mapLevel, this);

	// *******************************************************	
	player.Init(this, std::move(Vector2(1, 1)));
	player.SetPlayerDir(std::move(Vector2(1, 0)));
	// *******************************************************

	PlayableLevels::Init();
	GameStateManager::GetInstance()->SetBothStates(GameState::LEVEL_01);
}

// Update the level
void Level_01::Update()
{
	PlayableLevels::Update();
	// if paused, don't update
	if (pause.GetIsPaused())
		return;
}

// print out the chars
void Level_01::Render()
{
	PlayableLevels::Render();
	if (pause.GetIsPaused())
		return;
}

// When Exiting the level
void Level_01::Exit()
{
	// Call LevelManager to change to next map
	PlayableLevels::Exit();
}