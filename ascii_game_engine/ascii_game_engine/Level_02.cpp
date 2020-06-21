#include "Level_02.h"

Level_02::Level_02()
{

}

Level_02::~Level_02()
{

}

// Init the level
void Level_02::Init()
{
	const char* mapLevel = "../Game/Map/Default Maps/level_02.txt";
	map.Init(mapLevel, this);

	// *******************************************************	
	player.Init(map, std::move(Vector2(1, 1)));
	player.SetPlayerDir(std::move(Vector2(1, 0)));
	// *******************************************************

	FogLevels::Init();
	//fog.SetVisionLength(5);
	GameStateManager::GetInstance()->SetBothStates(GameState::LEVEL_02);
}

// Update the level
void Level_02::Update()
{
	FogLevels::Update();
	if (pause.GetIsPaused())
		return;
}

// print out the chars
void Level_02::Render()
{
	FogLevels::Render();
	if (pause.GetIsPaused())
		return;
}

// When Exiting the level
void Level_02::Exit()
{
	FogLevels::Exit();
}