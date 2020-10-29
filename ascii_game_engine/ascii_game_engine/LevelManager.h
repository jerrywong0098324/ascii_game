// LevelManager class to handle changing of level, from Menu to Game to Custom Map
#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Singleton.h"
#include "Menu.h"

class LevelManager : public Singleton<LevelManager>
{
public:
	// Getters
	Level* GetMapLevel();
	// change to the next level
	void NextLevel();
	// change to a specific map
	void NextLevel(const int mapIndex);

	void Init();

private:
	// Singleton definition
	friend class Singleton<LevelManager>;
	LevelManager();
	~LevelManager();

	void AddLevels(Level *level);
	virtual void free_memory();

	std::vector<Level*> levels;

	// index used to move between levels
	int mapIndex;

	// boolean to check if the level is switched
	bool isLevelChange;

};

#endif 