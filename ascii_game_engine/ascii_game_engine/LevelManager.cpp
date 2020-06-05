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
	++mapIndex;
}

// change to a specific map
void LevelManager::NextLevel(const int mapIndex)
{
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

//// Load all default map created by me
//void LevelManager::LoadDefaultMap()
//{
//	std::string maps; // file name of the default maps
//	std::ifstream inFile("../Map/default_maps.txt"); // Input file
//
//		// Check for any errors -> corrupted files, wrong file name etc
//	if (inFile.fail())
//	{
//		std::cerr << "Unable to open file: " << "../Map/default_maps.txt" << std::endl;
//		exit(1);
//	}
//
//	// Loop through till the end of file
//	while (!inFile.eof())
//	{
//		inFile >> maps;
//		mapLevels.push_back(maps);
//	}
//}