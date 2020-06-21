// Player class, what should my gameplay be..?
#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include "Vector2.h"
#include "GameStateManager.h"
#include "Inventory.h"

class Player
{
public:
	Player();
	~Player();

	// Return Reference to Player's Position (To make camera side scroll)
	Vector2 &GetRefPosition();
	// Return Player's Position
	Vector2 GetPosition() const;
	// Return Player's Direction
	Vector2 GetDirection() const;

	void SetPosition(const Vector2 pos);
	void SetMap(Map map);
	void SetPlayerDir(const Vector2 dir);

	// Init the player
	void Init(Map map, const Vector2 pos = Vector2(0, 0));
	// Update function to get player's input
	void Update();

private:
	// Put the player within game map
	void LimitPos();

	// Set the dir char
	void SetDirectionChar(const int dirChar);

	// Updates the player input
	void UpdatePlayer();
	// Moves the player and check for collision
	void MovePlayer();
	// Make sure player isn't going out of bounds
	void LimitPlayer();
	// Collision Detection
	bool DetectCollision(int x_pos, int y_pos) const;

	// Initialize inventory from save file
	void InitInventory();

	char playerChar[4];
	// player's position on the map
	Vector2 pos;
	// dir the player is currently facing
	Vector2 dir; // x = 1 (right), x = -1 (left), y = -1 (up), y = 1 (down)
	// determine which ascii character to use
	int dirChar;

	// ref to the playing map
	Map map;

	// Add Inventory here, can choose which item to use from inventory
	Inventory inventory;
	// Item in hand
	Item* currItem;
};

#endif 