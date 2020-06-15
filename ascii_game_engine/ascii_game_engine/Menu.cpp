#include "Menu.h"
#include "LevelManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

// Init the level
void Menu::Init()
{
	const char* mapLevel = "../Game/Map/Default Maps/menu.txt";
	map.Init(mapLevel);

	// ****************************************************************
	bgm = new Audio();
	bgm->Init("../Game/Audio/Menu/menu.ogg", 0.5f, true, false, true);
	bgm->Play();

	arrowSFX = new Audio();
	arrowSFX->Init("../Game/Audio/Menu/arrow1.ogg");

	selectSFX = new Audio();
	selectSFX->Init("../Game/Audio/Menu/select.ogg");
	// ****************************************************************

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
	UpdateEnterPressed();
}

// print out the chars
void Menu::Render()
{
	PrintMap();
}

// When Exiting the level
void Menu::Exit()
{
	// Call LevelManager to change to next map
	LevelManager::GetInstance()->NextLevel(mapIndex);
	SoundEngine::GetInstance()->StopAllAudio();
}

// Updates the arrow position
void Menu::UpdateArrow()
{
	char **menu = map.GetMap();
	// replacing current arrow position to an empty space
	menu[arrow_pos_y][arrow_pos_x] = ' ';

	MoveArrow();

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

	// new arrow position after player's input
	menu[arrow_pos_y][arrow_pos_x] = arrow;
}

// Move Arrow and play sound
void Menu::MoveArrow()
{
	if (enterPressed)
		return;

	if (UserInput::GetKeyDown(KeyCode::DownArrow))
	{
		++arrow_pos_y;
		++option;

		arrowSFX->Play();
	}
	else if (UserInput::GetKeyDown(KeyCode::UpArrow))
	{
		--arrow_pos_y;
		--option;

		arrowSFX->Play();
	}	
}

// Update user's enter input
void Menu::UpdateInput()
{
	if (UserInput::GetKeyDown(KeyCode::Enter))
	{
		enterPressed = true;
		selectSFX->Play();
	}
}

// Update time after enter key is pressed
void Menu::UpdateEnterPressed()
{
	if (!enterPressed)
		return;

	dt += StopWatch::GetInstance()->GetDeltaTime();
	if (dt < 0.3f)
		return;

	switch (option)
	{
		// play button
	case 1:
		GameStateManager::GetInstance()->SetCurrentGameState(GameState::GAME);
		mapIndex = 1;
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

// prints the map out
void Menu::PrintMap()
{
	int y = map.GetSizeY();

	for (int i = 0; i < y; ++i)
	{
		char *row = *(map.GetMap() + i);
		std::cout << row << std::endl;
	}
}