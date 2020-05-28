#include "Application.h"
#include "Timer.h"

const unsigned char FPS = 60; // FPS of the game
const unsigned int frameTime = 1000 / FPS; // time for each frame

void Application::Init()
{
	// Init LevelManager here
	StopWatch::GetInstance()->StartTimer();
}

void Application::Run()
{
	float dt = 0.0f;
	bool ended = false;

	// While game is not "exited"
	while (!ended)
	{
		// Level manager shit handling stuff here
		Game::GetInstance()->Init();

		// While level player is playing == curr level || game is not exited
		while (!ended)
		{
			// Updating the delta time
			StopWatch::GetInstance()->UpdateTimer();

			dt += StopWatch::GetInstance()->GetDeltaTime();
			std::cout << dt << std::endl;

			if (UserInput::GetKeyPress(KeyCode::Escape))
				ended = true;
				/*std::cout << "hello world" << std::endl;*/

			Game::GetInstance()->Update();
			Game::GetInstance()->Render();

			// Frame rate limiter
			StopWatch::GetInstance()->WaitUntil(frameTime);

			// Make the program wait for 0.1s before continuing
			//Sleep(100);

			// refreshes the console
			system("cls");
		}

		// refreshes the console
		system("cls"); // refresh one more time to be sure
		Game::GetInstance()->Exit();
	}
}

void Application::Exit()
{
	// free-ing all singleton memory here
	StopWatch::GetInstance()->free_memory();
}