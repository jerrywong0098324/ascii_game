/* 
Ice block: When player steps on it, will slide towards the initial direction he is facing.
		Unable to move out of the sliding path, but still able to update their direction
*/
#ifndef	ICE_H
#define ICE_H

#include "Block.h"
#include "Player.h"

class PlayableLevels;
class Ice : public Block
{
public:
	Ice(int id);
	virtual ~Ice();

	virtual void Init(Player* player, Level* level);
	// Updates the interaction between ice block and player
	virtual void Update();
	// Render player's and any block foreground with ice background
	virtual void Render();
	// Interactions when player is on top of the block
	virtual void Interactions();
	// Clear any memory if neccessary
	virtual void Exit();

	// Returns the block on the ice
	char GetBlockOnIce() const;

private:
	void InitIce();	
	// Player's interactions with ice
	void InteractIce();
	// Boolean to check if player is at the end of the ice block, collided with a wall or within the edge of the map
	bool AbleToSlide(const int& x, const int& y);

	// Updates if there's any other blocks on the ice
	void UpdateBlockOnIce();

	// Render player
	void RenderPlayer();
	// Render any block that will is on the ice
	void RenderBlock();

	char blockOnIce; // Gets the block on top of the ice
	int blockOrder; // block on ice order

	Player* player; // reference to the player
	Level* level; // reference to the map
	PlayableLevels* plptr; 
};

#endif