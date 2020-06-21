// // Pickaxe to break down boulder
#ifndef PICKAXE_H
#define PICKAXE_H

#include "Equipment.h"

class Pickaxe : public Equipment
{
public:
	Pickaxe();
	~Pickaxe();

	// Function to handle using of this item
	virtual void Use();
	// If I need to deallocate any memory
	virtual void Exit();

private:
	// Determine whether pickaxe is in use based on map and player's position
	void UpdatePickaxe();
};

#endif