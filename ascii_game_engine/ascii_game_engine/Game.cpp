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