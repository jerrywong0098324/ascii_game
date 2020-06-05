#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

// Init the level
void Menu::Init()
{
	const char* mapLevel = "../Map/Default Maps/menu.txt";
	map.Init(mapLevel);

	// init arrow y position
	arrow_pos_y = 12;

	// init for option variables
	option = 1;

	GameStateManager::GetInstance()->SetBothStates(GameState::MENU);
}

// Update the level
void Menu::Update()
{
	UpdateArrow();
	UpdateInput();
}

// print out the chars
void Menu::Render()
{
	PrintMap();
}

// When Exiting the level
void Menu::Exit()
{
	map.Exit();
	// Call LevelManager to change to next map
}

// Updates the arrow position
void Menu::UpdateArrow()
{
	char **menu = map.GetMap();
	menu[arrow_pos_y][arrow_pos_x] = ' ';

	if (UserInput::GetKeyDown(KeyCode::DownArrow))
	{
		++arrow_pos_y;
		++option;
	}
	else if (UserInput::GetKeyDown(KeyCode::UpArrow))
	{
		--arrow_pos_y;
		--option;
	}

	if (arrow_pos_y > max_y)
	{
		arrow_pos_y = min_y;
		option = min_op;

	}
	else if (arrow_pos_y < min_y)
	{
		arrow_pos_y = max_y;
		option = max_op;
	}

	menu[arrow_pos_y][arrow_pos_x] = arrow;
}

// Update user's enter input
void Menu::UpdateInput()
{
	if (UserInput::GetKeyDown(KeyCode::Enter))
	{
		switch (option)
		{
		// play button
		case 1:
			break;
		// highscore button
		case 2:
			break;
		// exit button
		case 3:
			GameStateManager::GetInstance()->SetCurrentGameState(GameState::EXIT);
			break;
		}
	}
}

// prints the map out
void Menu::PrintMap()
{
	int x = map.GetSizeX();
	int y = map.GetSizeY();

	for (int i = 0; i < y; ++i)
	{
		char *row = *(map.GetMap() + i);
		std::cout << row << std::endl;
	}
}