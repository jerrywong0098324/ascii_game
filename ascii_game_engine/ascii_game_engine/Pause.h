// Inherit from map, this is specific to when the game is Paused
#ifndef PAUSE_H
#define PAUSE_H

#include "Map.h"
#include "UserInput.h"
#include "GameStateManager.h"

class Pause : public Map
{
public:
	Pause();
	~Pause();

	// State of the game, is it paused?
	bool GetIsPaused() const;

	// Init
	virtual void Init(const char* map = "");
	// Updates the pause screen
	bool Update();
	// render the pause onto the screen
	void Render();
	// Exit
	void ExitP();

private:
	// Set the state of the pause when Esc button is pressed
	void PauseState();
	// Pause and Resume
	void PausedState();
	// Print the map
	void Print();
	// Update inputs from user
	void UpdateInputs();
	// Update the arrow movements
	void UpdateArrow();
	// Moves arrow
	void MoveArrow();
	// Wrap the arrow around
	void WrapArrow();
	// Update key press
	void UpdateEnterPress();

	int arrow_pos_x = 13, arrow_pos_y;
	int min_y = 11, max_y = 13;
	int option;
	int min_op = 1, max_op = 3;
	int mapIndex;
	bool isPaused = false;
	char arrow = '>';
};

#endif 