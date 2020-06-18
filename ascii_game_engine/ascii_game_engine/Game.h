// This is where the gameplay will occur
#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "Console.h"
#include "LevelManager.h"
#include "Player.h"
#include "Timer.h"

#include "MemoryLeak.h"

class Game : public Singleton<Game>
{
public:

	void Init();
	void Render();
	void Update();
	void Exit();

	virtual void free_memory();

	char* GetCollisionList() const;
	int GetTotalCollide() const;

private:
	// Singleton definition
	friend class Singleton<Game>;
	Game();
	~Game();

	void InitCollision();
	void OpenFile(std::vector<std::string>& res);
	void CreateCollisions(std::vector<std::string>& res);

	char *collideList;
	int totalCollide;
};

#endif