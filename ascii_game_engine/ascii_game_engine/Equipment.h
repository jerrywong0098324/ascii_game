// Equipment such as pickaxe and climbing ropes
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"
#include "Player.h"
#include "PlayableLevels.h"

class Equipment : public Item
{
public:
	Equipment() : player(nullptr), level(nullptr), map(nullptr) {};
	virtual ~Equipment() = 0 {};

	// To init the item
	virtual void Init(Player& player, Level* level, char** map) 
	{ 
		this->player = &player;
		this->level = level;
		this->map = map; 

		amount = 1;
		max_amt = 1;
	};
	// Function to handle using of this item
	virtual void Use() {};
	// If I need to deallocate any memory
	virtual void Exit() {};

protected:
	const Player* player; // reference to the player
	Level* level; // reference to the level
	char** map; // reference to the map
};

#endif