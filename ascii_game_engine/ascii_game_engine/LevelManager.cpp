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

// change to the next level in the next index
void LevelManager::NextLevel()
{
	if (mapIndex + 1 >= levels.size())
		return;

	SoundEngine::GetInstance()->StopAllAudio();
	levels[mapIndex]->GetMap().Exit();
	levels[mapIndex]->GetDuplicatedMap().Exit();
	++mapIndex;
}

// change to a specific map
void LevelManager::NextLevel(const int mapIndex)
{
	if (mapIndex >= levels.size() || mapIndex < 0)
		return;

	SoundEngine::GetInstance()->StopAllAudio();
	levels[this->mapIndex]->GetMap().Exit();
	levels[this->mapIndex]->GetDuplicatedMap().Exit();
	this->mapIndex = mapIndex;
}

void LevelManager::Init()
{
	AddLevels(new Menu()); // 0
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