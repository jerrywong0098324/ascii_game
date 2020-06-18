#include "Game.h"

Game::Game() : collideList(nullptr), totalCollide(0)
{
	Console::CreateConsole(420, 420);
	InitCollision();
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

void Game::InitCollision()
{
	std::vector<std::string> res;

	OpenFile(res);
	CreateCollisions(res);
}

void Game::OpenFile(std::vector<std::string>& res)
{
	const char* txtFile = "../Game/Collisions/collisions.txt";
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

void Game::CreateCollisions(std::vector<std::string>& res)
{
	totalCollide = res.size(); // total blocks of collision with player
	int ascii; // ascii code from .txt file

	// Create pointer for collisions
	collideList = new char[totalCollide];

	for (int i = 0; i < totalCollide; ++i)
	{
		ascii = std::stoi(res[i]);
		collideList[i] = (char)ascii;
	}
}