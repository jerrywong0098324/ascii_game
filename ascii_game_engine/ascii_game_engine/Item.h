// Abstract class to handle all kind of item, ranging from potions to pickaxe
#ifndef ITEM_H
#define ITEM_H

#include "ItemID.h"
#include "UserInput.h"
#include "MemoryLeak.h"
#include "Player.h"

class Item
{
public:
	Item() : max_amt(0), amount(0), id(ItemID::INVALID) {};
	virtual ~Item() = 0 {};

	// To init the item
	virtual void Init(int max_amt, int amount, ItemID id, Player* player) { this->max_amt = max_amt; this->amount = amount; this->id = id; this->player = player; };
	// Function to handle using of this item
	virtual void Use() {};
	// If I need to deallocate any memory
	virtual void Exit() {};

	void SetMaximum(const int max_amt) { this->max_amt = max_amt; }
	void SetAmount(const int amount) { this->amount = amount; }
	void SetItemID(const ItemID id) { this->id = id; }

	int GetMaximum() const { return max_amt; }
	int GetAmount() const { return amount; }
	ItemID GetItemID() const { return id; }

	void Add(const int amount = 1) { this->amount += amount; }

protected:
	int max_amt; // maximum amount I can carry this item in this slot
	int amount; // current amount I have of this item in this slot
	ItemID id; // using this variable to save into file
	const Player* player; // reference to the player

	int useButton = (int)KeyCode::F; // code for using Item
};

#endif