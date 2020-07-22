// Player class, what should my gameplay be..?
#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include "Vector2.h"
#include "GameStateManager.h"
#include "Inventory.h"
#include "PlayerStatus.h"

class Player
{
public:
	Player();
	~Player();

	// Init the player
	void Init(Level* level, const Vector2 pos = Vector2(0, 0));
	// Update function to get player's input
	void Update();
	// Render Inventory
	void Render(char** print);
	// Clear any necessary memory allocation
	void Exit();

	// Return Reference to Player's Position (To make camera side scroll)
	Vector2 &GetRefPosition();
	// Return Player's Position
	Vector2 GetPosition() const;
	// Return Player's Direction
	Vector2 GetDirection() const;
	// Return Player's current status
	PlayerStatus GetPlayerStatus() const;

	void SetPosition(const Vector2& pos);
	void SetPlayerDir(const Vector2& dir);
	void SetPlayerStatus(const PlayerStatus& state);

	// Add item into inventory
	void AddItem(Item* item);

	/*******************************************************************
				   PLAYER MOVEMENTS & COLLISION
	*******************************************************************/
	// Check if player is within map
	bool WithinMap() const;
	// ******************************************************************

private:
	/*******************************************************************
					   PLAYER MOVEMENTS & COLLISION
	*******************************************************************/
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
	bool DetectCollision(int x, int y) const;
	// ******************************************************************

	/*******************************************************************
					      INVENTORY & ITEM FEATURES
	*******************************************************************/
	// Initialize inventory from save file
	void InitInventory(Level* level);
	// Updates item the player is holding
	void UpdateItem();
	// Update item's interaction
	void UpdateItemInteraction();
	// Change item using 1 - 5
	void ChangeItem();
	// Change item using q and e
	void NextItem();
	// ******************************************************************

	/*******************************************************************
							SLIDING FEATURES
			  Behaviour when player interacts with ice blocks
	*******************************************************************/
public:
	bool CanSlide();
private:
	void Sliding();
	void UpdateSlide();
	void ResetSlide();

	float slide_dt;
	float slide_time;
	bool slide;
	// ******************************************************************

	char playerChar[4];
	// player's position on the map
	Vector2 pos;
	// dir the player is currently facing
	Vector2 dir; // x = 1 (right), x = -1 (left), y = -1 (up), y = 1 (down)
	// determine which ascii character to use
	int dirChar;

	// ref to the level
	Level* level;

	// Add Inventory here, can choose which item to use from inventory
	Inventory inventory;
	// Item in hand
	Item* currItem;
	int curr_item_index;
	int min_item_index, max_item_index, max_item_shown = 5; // @variable max_item_shown: how many items is shown in the "inventory" (game world)

	// Status
	PlayerStatus currState;
};

#endif 