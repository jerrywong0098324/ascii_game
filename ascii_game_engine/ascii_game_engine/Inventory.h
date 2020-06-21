// Inventory to store items
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	// Add into the inventory
	void AddItem(Item* item);
	// Remove from the inventory based on the item
	void DeleteItem(Item* item);
	// Remove from inventory based on index
	void DeleteItem(int index);

	// Save and delete allocated memory
	void Exit();

	Item* GetItem(int index);

private:
	// Clear Inventory (When exiting the level)
	void DeleteItems();

	std::vector<Item*> items;
};

#endif