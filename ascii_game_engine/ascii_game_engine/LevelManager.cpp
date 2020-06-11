#include "LevelManager.h"

LevelManager::LevelManager() : mapIndex(0), isLevelChange(false)
{

}

LevelManager::~LevelManager()
{

}

Level* LevelManager::GetMapLevel()
{
	return levels[mapIndex];
}

// change to the next level
void LevelManager::NextLevel()
{
	levels[mapIndex]->GetMap().Exit();
	++mapIndex;
}

// change to a specific map
void LevelManager::NextLevel(const int mapIndex)
{
	levels[mapIndex]->GetMap().Exit();
	this->mapIndex = mapIndex;
}

void LevelManager::Init()
{
	AddLevels(new Menu());
}

void LevelManager::AddLevels(Level *level)
{
	levels.push_back(level);
}

void LevelManager::free_memory()
{
	for (int i = 0; i < levels.size(); ++i)
	{
		delete levels[i];
		levels[i] = nullptr;
	}
	Singleton::free_memory();
}