// Abstract class to contain side scrolling for all playable levels
#ifndef PLAYABLE_LEVELS_H
#define PLAYABLE_LEVELS_H

#include "Level.h"
#include "Player.h"
#include "Pause.h"
#include "Block.h"

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
							BLOCKS FEATURE
	*******************************************************************/
	// Add block into a vector
	void AddBlock(Block* block);
	// Delete the block at the position
	void DeleteBlock(Block* block);
	// Returns true if the block at this position is not this variable 'c'
	bool GetNotThisBlock(const Vector2& pos, const char& c);
	// Returns a reference to the block based on the position (nullptr if nth)
	Block* GetBlock(const Vector2& pos) const;
	Player& GetRefPlayer();
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

	void InitPrint();
	void DeletePrint();

	const Vector2 *pos; // player's pos

	/*******************************************************************
							BLOCKS FEATURE
	*******************************************************************/
	// Update blocks
	void UpdateBlocks();
	// Clear any remaining memory of blocks from the level
	void DeleteBlocks();

	// reference to blocks on the map
	std::vector<Block*> blocks; 
	// ******************************************************************

protected:
	int XLimit();
	int YLimit();

	int x_buffer, y_buffer; // buffer to know where to start printing the map from
	char **print; // using this 2d dynamic array to print out the map
	Player player;
	// ******************************************************************

	/*******************************************************************
							PAUSED FEATURE
	*******************************************************************/
	// "Map" to print out paused screen
	Pause pause;
	// ******************************************************************
};

#endif