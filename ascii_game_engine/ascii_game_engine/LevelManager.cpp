#include "LevelManager.h"
#include "AudioManager.h"

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
	SoundEngine::GetInstance()->StopAllAudio();
	levels[mapIndex]->GetMap().Exit();
	++mapIndex;
}

// change to a specific map
void LevelManager::NextLevel(const int mapIndex)
{
	SoundEngine::GetInstance()->StopAllAudio();
	levels[this->mapIndex]->GetMap().Exit();
	this->mapIndex = mapIndex;
}

void LevelManager::Init()
{
	AddLevels(new Menu()); // 0
	AddLevels(new Level_01()); // 1
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