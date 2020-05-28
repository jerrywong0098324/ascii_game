#include "Game.h"


Game::Game()
{
	console = Console(360, 360);
}

Game::~Game()
{

}

void Game::Init()
{
	//currState = LevelManager::GetInstance()->GetGameState();

	//test.Init("../Map/map_example.txt");

	//camera = Camera(&player.GetRefPosition());
	//camera.SetGameState(currState);
	//camera.SetMap(LevelManager::GetInstance()->GetMap());
}

void Game::Render()
{
	// Camera render here
	camera.Render();
}

void Game::Update()
{

}

void Game::Exit()
{
	// Call Level to clear memory
	free_memory();
}