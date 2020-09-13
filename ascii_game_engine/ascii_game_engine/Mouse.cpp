#include "Mouse.h"
#include "GameStateManager.h"
#include <thread>

Mouse::Mouse()
{

}

Mouse::~Mouse()
{

}

// Kick off a worker thread to run update loop individually
void Mouse::Init()
{
	HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
	if (!SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS))
	{
		// prints out error message
		Error::MyErrorExit("SetConsoleMode @ Mouse.cpp");
	}

	SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	std::thread worker(&Mouse::Update, this); // start a new thread for mouse update
	worker.detach(); // detach so that a worker thread can update the mouse position independently
}

// Updates the mouse position whenever there is a mouse input from the user
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

void Mouse::free_memory()
{
	Singleton::free_memory();
}