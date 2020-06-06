#include "Game.h"

Game::Game()
{
	Console::CreateConsole(420, 420);
}

Game::~Game()
{

}

void Game::Init()
{
	LevelManager::GetInstance()->GetMapLevel()->Init();

	//currState = LevelManager::GetInstance()->GetGameState();
	//test.Init("../Map/map_example.txt");
	//camera = Camera(&player.GetRefPosition());
	//camera.SetGameState(currState);
	//camera.SetMap(LevelManager::GetInstance()->GetMap());
}

void Game::Render()
{
	LevelManager::GetInstance()->GetMapLevel()->Render();
}

void Game::Update()
{
	LevelManager::GetInstance()->GetMapLevel()->Update();

	dt += StopWatch::GetInstance()->GetDeltaTime();
	//std::cout << dt << std::endl;

	player.Update();
}

void Game::Exit()
{
	// Call Level to clear memory
	LevelManager::GetInstance()->GetMapLevel()->Exit();
}