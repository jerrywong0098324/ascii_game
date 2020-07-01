// Boulder that the player can push
#ifndef BOULDER_H
#define BOULDER_H

#include "Block.h"
#include "Player.h"

class Boulder : public Block
{
public:
	Boulder(int id);
	~Boulder();

	virtual void Init(Player* player, Level* level);
	// Updates the interaction between ice block and player
	virtual void Update();
	// Interactions when player is on top of the block
	virtual void Interactions();
	// Clear any memory if neccessary
	virtual void Exit();

private:
	void InitBoulder();
	void InteractBoulder();
	// Check if can push
	bool AbleToPush(const int& x, const int& y);

	Vector2 original_pos;

	Player* player; // reference to the player
	Level* level; // reference to the map
};

#endif