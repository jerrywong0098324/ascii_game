#include "Inventory.h"
#include "Item.h"

Inventory::Inventory()
{

}

Inventory::~Inventory()
{

}

// Add into the inventory, returns size of inventory
int Inventory::AddItem(Item* item)
{
	// don't add into the inventory if there's another of the same item, instead just add to the amount
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->GetItemID() == item->GetItemID())
		{
			item->Add(); // add one to the collection
			if (item->GetAmount() >= item->GetMaximum())
				item->SetAmount(item->GetMaximum());
			return items.size();
		}
	}
	// No such item in the inventory, add it inside
	items.push_back(item);
	return items.size();
}

// Remove from the inventory
void Inventory::DeleteItem(Item* item)
{
	// loop through inventory to find the item
	for (int i = 0; i < items.size(); ++i)
	{
		if (items[i]->GetItemID() == item->GetItemID())
		{
			// deallocates any memory
			items[i]->Exit();
			delete items[i];
			items[i] = nullptr;

			// remove from the vector
			items.erase(items.begin() + i);
			break; // break out of the loop
		}
	}
}

// Remove from inventory based on index
void Inventory::DeleteItem(int index)
{
	// deallocates any memory
	items[index]->Exit();
	delete items[index];
	items[index] = nullptr;

	// remove from the vector
	items.erase(items.begin() + index);
}

// Clear Inventory (When exiting the level)
void Inventory::DeleteItems()
{
	for (int i = 0; i < items.size(); ++i)
	{
		items[i]->Exit();
		delete items[i];
		items[i] = nullptr;
	}
}

// Save and delete allocated memory
void Inventory::Exit()
{
	DeleteItems();
}

Item* Inventory::GetItem(int index)
{
	if (index >= items.size())
		return nullptr;
	return items[index];
}