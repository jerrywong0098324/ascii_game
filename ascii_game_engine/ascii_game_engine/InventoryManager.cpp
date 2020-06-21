#include "InventoryManager.h"
#include "FileManager.h"
#include "Game.h"

// Put items into inventory from save file
std::vector<Item*> InventoryManager::InitInventory(Level* level, Player* player)
{
	/* 
		Inventory save file eg 
		ItemID,amount,max [0]
		1,1,1			  [1]
		2,10,20			  [2]
	*/
	std::string file = "../Game/Save/Inventory/";
	file += Game::GetInstance()->GetSaveFile();

	std::vector<std::string> res = FileManager::LoadFile(file.c_str());
	std::vector<Item*> items;
	int max_amt = 0, amt = 0;
	ItemID id = ItemID::INVALID;

	for (int i = 1; i < res.size(); ++i)
	{
		GetData(res[i], max_amt, amt, id);
		Item* item = InitItem(max_amt, amt, id, level, player);
		items.push_back(item);
	}

	return items; // return the vector
}

// Init item based on ItemID
Item* InventoryManager::InitItem(int max_amt, int amount, ItemID id, Level* level, Player* player)
{
	Item* item = nullptr;
	switch (id)
	{
		case ItemID::TORCH:
		{

			break;
		}
		case ItemID::PICKAXE:
		{
			item = new Pickaxe(); // create new pickaxe
			item->Init(max_amt, amount, id, player); // init item
			Pickaxe* pa = dynamic_cast<Pickaxe*>(item);
			pa->Init(level); // init equipment
			break;
		}
		case ItemID::HP_POTS:
		{

			break;
		}
	}
	return item;
}

// Extract data from the .txt file
void InventoryManager::GetData(std::string res, int& max_amt, int& amt, ItemID& id)
{
	std::string num;
	int data;

	while (true) // extract number for ItemID
	{
		if (res[0] == ',') // break if it's ,
			break;
		num += res[0]; // add first number to string
		res.erase(res.begin()); // erase first char from res
	}

	data = std::stoi(num);
	id = (ItemID)data; // init ItemID
	res.erase(res.begin()); // clear ',' from the string
	num.clear(); // clear num string
	// *****************************************************************
	while (true) // extract number for amount
	{
		if (res[0] == ',')
			break;
		num += res[0];
		res.erase(res.begin());
	}

	amt = std::stoi(num); // init amt
	res.erase(res.begin());
	num.clear();
	// *****************************************************************
	while (res.size() != 0) // extract number for max_amt
	{
		if (res[0] == ',')
			break;
		num += res[0];
		res.erase(res.begin());
	}
	max_amt = std::stoi(num); // init amt
}