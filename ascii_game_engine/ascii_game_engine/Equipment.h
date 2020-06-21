// Equipment such as pickaxe and climbing ropes
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"
#include "PlayableLevels.h"

class Equipment : public Item
{
public:
	Equipment() : level(nullptr) {};
	virtual ~Equipment() = 0 {};

	// To init the item
	virtual void Init(Level* level) 
	{ 
		this->level = level;

		amount = 1;
		max_amt = 1;
	};
	// Function to handle using of this item
	virtual void Use() {};
	// If I need to deallocate any memory
	virtual void Exit() {};

protected:
	Level* level; // reference to the level
};

#endif