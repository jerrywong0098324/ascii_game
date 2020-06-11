#include "Application.h"

const unsigned char FPS = 60; // FPS of the game
const unsigned int frameTime = 1000 / FPS; // time for each frame

void Application::Init()
{
	// Init LevelManager here	
	StopWatch::GetInstance()->StartTimer();
	LevelManager::GetInstance()->Init();
}

void Application::Run()
{
	// While game is not "exited"
	while (GameStateManager::GetInstance()->GetCurrentGameState() != GameState::EXIT)
	{
		// Level manager shit handling stuff here
		Game::GetInstance()->Init();

		// While level player is playing == curr level || game is not exited
		while (GameStateManager::GetInstance()->GetCurrentGameState() != GameState::EXIT)
		{
			// Updating the delta time
			StopWatch::GetInstance()->UpdateTimer();

			Game::GetInstance()->Update();
			Game::GetInstance()->Render();

			// Frame rate limiter
			StopWatch::GetInstance()->WaitUntil(frameTime);

			// Make the program wait for 0.1s before continuing
			Sleep(50);

			// refreshes the console
			//system("cls");

			if (GameStateManager::GetInstance()->GetCurrentGameState() != GameStateManager::GetInstance()->GetPreviousGameState())
				break;
		}

		// refreshes the console
		system("cls"); // refresh one more time to be sure
		Game::GetInstance()->Exit();
	}
}

void Application::Exit()
{
	// free-ing all singleton memory here
	SingletonManager::FreeAll();	
	AudioManager::FreeAll();
}