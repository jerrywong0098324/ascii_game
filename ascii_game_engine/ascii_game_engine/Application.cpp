#include "Application.h"
#include "Timer.h"

const unsigned char FPS = 60; // FPS of the game
const unsigned int frameTime = 1000 / FPS; // time for each frame

void Application::Init()
{
	Game::GetInstance()->Init();
	StopWatch::GetInstance()->StartTimer();
}

void Application::Run()
{
	while (!UserInput::GetInstance()->GetKeyDown(KeyCode::Escape))
	{
		// Updating the delta time
		StopWatch::GetInstance()->UpdateTimer();

		Game::GetInstance()->Update();
		Game::GetInstance()->Render();

		// Frame rate limiter
		StopWatch::GetInstance()->WaitUntil(frameTime);

		// Make the program wait for 0.1s before continuing
		//Sleep(100);

		// refreshes the console
		system("cls");
	}
}

void Application::Exit()
{
	Game::GetInstance()->Exit();
}