#include "Pause.h"
#include "LevelManager.h"

Pause::Pause()
{

}

Pause::~Pause()
{

}

// State of the game, is it paused?
bool Pause::GetIsPaused() const
{
	return isPaused;
}

// Init
void Pause::Init(const char* map)
{
	Map::Init(map);
	arrow_pos_y = min_y;
	option = min_op;
	isPaused = false;
}

// Updates the pause screen
bool Pause::Update()
{
	PauseState(); // Enable the game to go into pause
	UpdateInputs(); // Update inputs from user when the game is paused
	return isPaused;
}

// render the pause onto the screen
void Pause::Render()
{
	Print();
}

void Pause::ExitP()
{
	Map::Exit();
	LevelManager::GetInstance()->NextLevel(mapIndex);
}

// Set the state of the pause when Esc button is pressed
void Pause::PauseState()
{
	if (UserInput::GetKeyDown(KeyCode::Escape))
		PausedState();
}

// Pause and Resume
void Pause::PausedState()
{
	isPaused = !isPaused;
	map[arrow_pos_y][arrow_pos_x] = ' ';
	arrow_pos_y = min_y;
	option = min_op;
}

// Print the map
void Pause::Print()
{
	if (!isPaused) // don't print pause screen if its not pause
		return;

	for (int i = 0; i < y; ++i)
	{
		char* row = *(map + i);
		std::cout << row << std::endl;
	}
}

// Update inputs from user
void Pause::UpdateInputs()
{
	if (!isPaused) // won't update any inputs from here is game is not paused
		return;

	UpdateArrow();
	UpdateEnterPress();
}

// Update the arrow movements
void Pause::UpdateArrow()
{
	// replace current position with an empty space
	map[arrow_pos_y][arrow_pos_x] = ' '; 

	MoveArrow();
	WrapArrow();

	// new arrow position after player's input
	map[arrow_pos_y][arrow_pos_x] = arrow;
}

// Moves arrow
void Pause::MoveArrow()
{
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
}

// Wrap the arrow around
void Pause::WrapArrow()
{
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
}

// Update key press
void Pause::UpdateEnterPress()
{
	if (!UserInput::GetKeyDown(KeyCode::Enter)) // never press enter yet
		return;

	switch (option)
	{
	case 1: // main menu
		GameStateManager::GetInstance()->SetCurrentGameState(GameState::CHANGE_LEVEL);
		mapIndex = (int)GameState::MENU;
		break;
	case 2: // resume
		PausedState();
		break; 
	case 3: // exit
		GameStateManager::GetInstance()->SetCurrentGameState(GameState::EXIT);
		break;
	}
}