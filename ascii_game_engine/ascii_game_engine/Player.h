// Player class, what should my gameplay be..?
#ifndef PLAYER_H
#define PLAYER_H

#include "Vector2.h"

class Player
{
public:
	Player();
	~Player();

	// Return Reference to Player's Position
	Vector2 &GetRefPosition();
	// Return Player's Position
	Vector2 GetPosition();

	// Update function to get player's input
	void Update();

private:
	// player's position on the map
	Vector2 pos;
	// dir the player is currently facing
	int dir; // x = 1 (right), x = -1 (left), y = 1 (up), y = -1 (down)
};

#endif 