#include "Application.h"
#include "Timer.h"

const unsigned char FPS = 60; // FPS of the game
const unsigned int frameTime = 1000 / FPS; // time for each frame

void Application::Init()
{
	Game::GetInstance()->Init();
	//StopWatch::GetInstance()->StartTimer();
	timer.StartTimer();
}

void Application::Run()
{
	while (!GetKeyState(VK_ESCAPE))
	{
		// Updating the delta time
		//StopWatch::GetInstance()->GetDeltaTime();

		Game::GetInstance()->Update();
		Game::GetInstance()->Render();
		// refreshes the console
		system("cls");

		// Frame rate limiter
		timer.WaitUntil(frameTime);
		//StopWatch::GetInstance()->WaitUntil(frameTime);

		// Make the program wait for 0.5s before continuing
		Sleep(500);
	}
}

void Application::Exit()
{
	Game::GetInstance()->Exit();
}