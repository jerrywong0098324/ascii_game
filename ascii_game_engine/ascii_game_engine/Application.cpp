#include "Application.h"

void Init()
{
	Game::GetInstance()->Init();
}

void Update()
{
	Game::GetInstance()->Update();
}

void Render()
{
	Game::GetInstance()->Render();
}

void Shutdown()
{
	Game::GetInstance()->Shutdown();
}

int main()
{
	Init();
	while (!GetKeyState(VK_ESCAPE))
	{
		Update();
		Render();
		// refreshes the console
		system("cls");
	}
	Shutdown();
}