// // Pickaxe to break down boulder
#ifndef PICKAXE_H
#define PICKAXE_H

#include "Equipment.h"

class Pickaxe : public Equipment
{
public:
	Pickaxe();
	~Pickaxe();

	// Init function
	virtual void Init(Level* level);
	// Function to handle using of this item
	virtual void Use();
	// If I need to deallocate any memory
	virtual void Exit();

private:
	// Can use pickaxe every 1 sec
	void UpdatePickaxeStatus();
	// Determine whether pickaxe is in use based on map and player's position
	void UpdatePickaxe();
	// Reset pickStatus and relevant data
	void Reset();

	float dt;
	bool pickStatus; // true when dt >= 1s
};

#endif