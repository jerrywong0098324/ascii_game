#include "Mouse.h"
#include "GameStateManager.h"
#include <thread>

Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}

void Mouse::Init()
{
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	if (!SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS))
	{
		// prints out error message
		Error::MyErrorExit("SetConsoleMode @ Mouse.cpp");
	}

	SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	std::thread worker(&Mouse::Update, this);
	worker.detach(); // detach so that a worker thread can update the mouse position independently
}

void Mouse::Update()
{
	while (GameStateManager::GetInstance()->GetCurrentGameState() != GameState::EXIT)
	{
		INPUT_RECORD InputRecord;
		DWORD Events;
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &InputRecord, 1, &Events);

		switch (InputRecord.EventType)
		{
		case MOUSE_EVENT:
		{
			position.Set(InputRecord.Event.MouseEvent.dwMousePosition.X, InputRecord.Event.MouseEvent.dwMousePosition.Y);
			break;
		}
		default:
			break;
		}

		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	}
}

void Mouse::Exit()
{

}

Vector2 Mouse::GetPosition()
{
	return position;
}