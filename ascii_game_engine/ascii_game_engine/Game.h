// This is where the gameplay will occur
#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "Console.h"
#include "LevelManager.h"
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

	// Check collision
	bool DetectCollision(const char& c);
	char* GetWallList() const;
	int GetTotalWall() const;
	char* GetReplaceList() const;
	int GetTotalReplace() const;

	/*******************************************************************
						SAVING FEATURE
	*******************************************************************/
	void SetContinue(const bool cont); // set true if player is continuing from save file
	void SetSaveFile(const char* saveFile); // which save file is the player using

	bool GetContinue() const;
	const char* GetSaveFile() const;

private:
	// Singleton definition
	friend class Singleton<Game>;
	Game();
	~Game();

	void InitCollision();
	void InitWalls();
	void InitTemporaryCharacters();
	// @param useAscii: in the .txt file, use decimal code for the ascii characters you are using
	void CreateCharArray(std::vector<std::string>& res, int &refSize, char* &list, bool useAscii = true);

	char* collideList; // used for collision with player
	char* wallList; // used for fog
	char* replaceList; // list of temporary characters to be replaced in Map.cpp
	int totalCollide;
	int totalWall;
	int totalReplace;

	/*******************************************************************
							SAVING FEATURE
	*******************************************************************/
	const char* saveFile; // use to save into which save file, total 3 save files
	bool cont; // boolean to check if continue or new game
	// ******************************************************************
};

#endif