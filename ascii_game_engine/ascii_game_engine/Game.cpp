#include "Game.h"

Game::Game() : collideList(nullptr), totalCollide(0)
{
	Console::CreateConsole(420, 420);
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

char* Game::GetCollisionList() const
{
	return collideList;
}

int Game::GetTotalCollide() const
{
	return totalCollide;
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

void Game::InitCollision()
{
	std::vector<std::string> res;

	OpenFile(res, "../Game/Collisions/collisions.txt");
	CreateCharArray(res, totalCollide, collideList);
}

void Game::InitWalls()
{
	std::vector<std::string> res;
	OpenFile(res, "../Game/Walls/walls.txt");
	CreateCharArray(res, totalWall, wallList);
}

void Game::InitTemporaryCharacters()
{
	std::vector<std::string> res;
	OpenFile(res, "../Game/Temporary Characters/temp.txt");
	CreateCharArray(res, totalReplace, replaceList, false); // using normal characters for easier reference
}

void Game::OpenFile(std::vector<std::string>& res, const char* txtFile)
{
	std::string items; // ascii code from .txt file
	std::ifstream inFile(txtFile);

	// Check for any errors, close program if fail
	if (inFile.fail())
	{
		std::cerr << "Unable to open file: " << txtFile << std::endl;
		exit(1);
	}

	// Loop till the end of file
	while (!inFile.eof())
	{
		inFile >> items;
		res.push_back(items);
	}
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