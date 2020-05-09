#include "Application.h"

void Application::Init()
{
	Game::GetInstance()->Init();
}

void Application::Run()
{
	while (!GetKeyState(VK_ESCAPE))
	{
		Game::GetInstance()->Update();
		Game::GetInstance()->Render();
		// refreshes the console
		system("cls");
	}
}

void Application::Exit()
{
	Game::GetInstance()->Exit();
}