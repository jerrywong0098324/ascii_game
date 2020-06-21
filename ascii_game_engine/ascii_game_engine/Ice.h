/* 
Ice block: When player steps on it, will slide towards the initial direction he is facing.
		Unable to move out of the sliding path, but still able to update their direction
*/
#ifndef	ICE_H
#define ICE_H

#include "Block.h"
#include "Player.h"

class Ice : public Block
{
public:
	Ice(int id);
	virtual ~Ice();

	virtual void Init(Player* player);
	// Updates the interaction between ice block and player
	virtual void Update();
	// Interactions when player is on top of the block
	virtual void Interactions();
	// Clear any memory if neccessary
	virtual void Exit();

private:
	Vector2 slideDir; // sliding direction of the player
	Player* player; // reference to the player
};

#endif