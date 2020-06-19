// Class to handle the main menu
#ifndef MENU_H
#define MENU_H

#include "Level.h"

class Menu : public Level
{
public:
	Menu();
	virtual ~Menu();

	// Init the level
	virtual void Init();
	// Update the level
	virtual void Update();
	// print out the chars
	virtual void Render();
	// When Exiting the level
	virtual void Exit();

private:
	// Updates the arrow position
	void UpdateArrow();
	// Move Arrow and play sound
	void MoveArrow();
	// Update user's enter input
	void UpdateInput();
	// Update time after enter key is pressed
	void UpdateEnterPressed();
	// prints the map out
	void PrintMap();

	// display the arrow key for player to "choose" their option (between Play, Exit, Highscore)
	char arrow = '>';
	// arrow position
	const int arrow_pos_x = 13;
	int arrow_pos_y;
	// max and min of y pos
	const int min_y = 13, max_y = 15;

	// variables for play, highscore, exit
	int option = 0;
	const int min_op = 1, max_op = 3;

	bool enterPressed;
	float dt = 0.0f;

	// next map
	int mapIndex = 0;

	Audio *bgm;
	Audio *arrowSFX;
	Audio *selectSFX;
};

#endif