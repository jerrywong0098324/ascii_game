// Abstract class to contain side scrolling for all playable levels
#ifndef PLAYABLE_LEVELS_H
#define PLAYABLE_LEVELS_H

#include "Level.h"
#include "Player.h"
#include "Pause.h"

class PlayableLevels : public Level
{
public:
	PlayableLevels();
	~PlayableLevels() = 0;

	// Init the level
	virtual void Init();
	// Update the level (Call this update in all Levels)
	virtual void Update();
	// print out the chars
	virtual void Render();
	// When Exiting the level
	virtual void Exit();

private:
	/*******************************************************************
						SIDE SCROLLING FEATURE
	*******************************************************************/
	int ScrollLimitX(int multiplier = 1, int divider = 1);
	int ScrollLimitY(int multiplier = 1, int divider = 1);

	void ScrollRight();
	void ScrollLeft();
	void ScrollUp();
	void ScrollDown();

	// init buffer based on player's pos
	void InitBuffer();

	void SideScroll();
	void PrintMap();
	int XLimit();
	int YLimit();

	int x_buffer, y_buffer;
	Vector2* pos;
	// ******************************************************************

protected:
	Player player;

	/*******************************************************************
							PAUSED FEATURE
	*******************************************************************/
	// "Map" to print out paused screen
	Pause pause;
	// ******************************************************************
};

#endif 