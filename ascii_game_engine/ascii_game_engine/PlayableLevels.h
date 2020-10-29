// Abstract class to contain side scrolling for all playable levels
#ifndef PLAYABLE_LEVELS_H
#define PLAYABLE_LEVELS_H

#include "Level.h"
#include "Pause.h"

class PlayableLevels : public Level
{
public:
	PlayableLevels();
	~PlayableLevels() = 0;

	/*******************************************************************
						CALL THESE IN CHILD CLASSES
	*******************************************************************/
	// Init the level
	virtual void Init();
	// Update the level (Call this update in all Levels)
	virtual void Update();
	// print out the chars
	virtual void Render();
	// When Exiting the level
	virtual void Exit();
	// ******************************************************************

	/*******************************************************************
							GETTERS AND SETTERS
	*******************************************************************/
	int GetXBuffer() const;
	int GetYBuffer() const;
	// ******************************************************************

	/*******************************************************************
							PAUSE FEATURE
	*******************************************************************/
	bool GetIsPaused() const;

private:
	/*******************************************************************
						SIDE SCROLLING FEATURE
	*******************************************************************/
	void SideScroll(); 

	int ScrollRightLimit(int multiplier = 1, int divider = 1);
	int ScrollLeftLimit(int multiplier = 1, int divider = 1);
	int ScrollUpLimit(int multiplier = 1, int divider = 1);
	int ScrollDownLimit(int multiplier = 1, int divider = 1);

	void ScrollRight();
	void ScrollLeft();
	void ScrollUp();
	void ScrollDown();

	// init buffer based on player's pos, putting the playing in the middle of the screen
	void InitBuffer();
	void InitXBuffer();
	void InitYBuffer();

	void PrintMap(); // overriding it in FogLevels

	const Vector2 *pos; // player's pos

protected:
	int XLimit();
	int YLimit();

	int x_buffer, y_buffer; // buffer to know where to start printing the map from
	char **print; // using this 2d dynamic array to print out the map
	// ******************************************************************

	/*******************************************************************
							PAUSED FEATURE
	*******************************************************************/
	// "Map" to print out paused screen
	Pause pause;
	// ******************************************************************
};

#endif