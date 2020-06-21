// Converts ItemID from save file and initialised it for the player's inventory
#ifndef	INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "Pickaxe.h"

class InventoryManager
{
public:
	InventoryManager() {};
	~InventoryManager() {};

	// Put items into inventory from save file
	static std::vector<Item*> InitInventory(Level* level, Player* player);

private:
	// Init item based on ItemID
	static Item* InitItem(int max_amt, int amount, ItemID id, Level* level, Player* player);
	// Extract data from the .txt file
	static void GetData(std::string res, int& max_amt, int& amt, ItemID& id);
};

#endif