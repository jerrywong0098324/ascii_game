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
		// Set variables in Renderer class to be the default
		Renderer::GetInstance()->Init();
		// Level manager shit handling stuff here
		Game::GetInstance()->Init();

		// While level player is playing == curr level || game is not exited
		while (GameStateManager::GetInstance()->GetCurrentGameState() != GameState::EXIT)
		{
			// Updating the delta time
			StopWatch::GetInstance()->UpdateTimer();

			Game::GetInstance()->Update();
			// Use game level's render function and call upon Renderer class to print onto screen
			Game::GetInstance()->Render();
			// This is the true render function to put characters onto screen
			Renderer::GetInstance()->Render();

			// Include a renderer class to display game characters onto the screen
			// Renderer Class handles colors and printing of characters at specific position

			// Frame rate limiter
			StopWatch::GetInstance()->WaitUntil(frameTime);

			// Make the program wait for 0.1s before continuing
			Sleep(50);

			// refreshes the console
			//system("cls");

			Console::ClearScreen();
			Console::ClearBox();

			if (GameStateManager::GetInstance()->GetCurrentGameState() != GameStateManager::GetInstance()->GetPreviousGameState())
				break;
		}

		// refreshes the console
		system("cls"); // refresh one more time to be sure
		Game::GetInstance()->Exit();
		Renderer::GetInstance()->Exit();
	}
}

void Application::Exit()
{
	// free-ing all singleton memory here
	SingletonManager::FreeAll();
}

// Clear all memory when cross button is pressed
void Application::Terminate()
{
	GameStateManager::GetInstance()->SetCurrentGameState(GameState::EXIT);
	Game::GetInstance()->Exit();
	SingletonManager::FreeAll();
}