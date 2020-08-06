#include "Game.h"
#include "FileManager.h"

Game::Game() : collideList(nullptr), totalCollide(0)
{
	InitCollision();
	InitWalls();
	InitTemporaryCharacters();
}

Game::~Game()
{

}

void Game::Init()
{
	LevelManager::GetInstance()->GetMapLevel()->Init();
}

void Game::Render()
{
	LevelManager::GetInstance()->GetMapLevel()->Render();
}

void Game::Update()
{
	LevelManager::GetInstance()->GetMapLevel()->Update();
}

void Game::Exit()
{
	// Call Level to clear memory
	LevelManager::GetInstance()->GetMapLevel()->Exit();
}

void Game::free_memory()
{
	delete[] collideList;
	collideList = nullptr;

	delete[] wallList;
	wallList = nullptr;

	delete[] replaceList;
	replaceList = nullptr;

	Singleton::free_memory();
}

// Check collision (returns true if 
bool Game::DetectCollision(const char& c)
{
	// loop through to see if the next block ahead of player is something that cannot be collided with
	for (int i = 0; i < totalCollide; ++i)
	{
		if (c == collideList[i]) // the next character c is a wall, so collision is detected
			return true;
	}
	return false;
}

char* Game::GetWallList() const
{
	return wallList;
}

int Game::GetTotalWall() const
{
	return totalWall;
}

char* Game::GetReplaceList() const
{
	return replaceList;
}

int Game::GetTotalReplace() const
{
	return totalReplace;
}

/*******************************************************************
					SAVING FEATURE
*******************************************************************/
// set true if player is continuing from save file
void Game::SetContinue(const bool cont)
{
	this->cont = cont;
}

// which save file is the player using
void Game::SetSaveFile(const char* saveFile)
{
	this->saveFile = saveFile;
}

bool Game::GetContinue() const
{
	return cont;
}

const char* Game::GetSaveFile() const
{
	return saveFile;
}

// *******************************************************************

void Game::InitCollision()
{
	std::vector<std::string> res = FileManager::LoadFile("../Game/Collisions/collisions.txt");
	CreateCharArray(res, totalCollide, collideList);
}

void Game::InitWalls()
{
	std::vector<std::string> res = FileManager::LoadFile("../Game/Walls/walls.txt");
	CreateCharArray(res, totalWall, wallList);
}

void Game::InitTemporaryCharacters()
{
	std::vector<std::string> res = FileManager::LoadFile("../Game/Temporary Characters/temp.txt");
	CreateCharArray(res, totalReplace, replaceList, false); // using normal characters for easier reference
}

void Game::CreateCharArray(std::vector<std::string>& res, int &refSize, char* &list, bool useAscii)
{
	refSize = res.size(); // total blocks of collision with player
	int ascii; // ascii code from .txt file

	// Create pointer for collisions
	list = new char[refSize];

	if (useAscii)
	{
		for (int i = 0; i < refSize; ++i)
		{
			ascii = std::stoi(res[i]);
			list[i] = (char)ascii;
		}
	}
	else
	{
		for (int i = 0; i < refSize; ++i)
			list[i] = res[i][0];
	}
}