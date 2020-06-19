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
	char* GetWallList() const;
	int GetTotalWall() const;

private:
	// Singleton definition
	friend class Singleton<Game>;
	Game();
	~Game();

	void InitCollision();
	void InitWalls();
	void OpenFile(std::vector<std::string>& res, const char* txtFile);
	void CreateCharArray(std::vector<std::string>& res, int &refSize, char* &list);

	char* collideList; // used for collision with player
	char* wallList; // used for fog
	int totalCollide;
	int totalWall;
};

#endif