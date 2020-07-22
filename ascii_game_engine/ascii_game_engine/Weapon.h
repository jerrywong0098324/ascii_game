// Can create melee and range weapon
#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon() : damage(0) {};
	virtual ~Weapon() = 0 {};

	int GetDamage() const { return damage; };

	// To init the item
	virtual void Init() {};
	// Function to handle using of this item
	virtual void Use() {};
	// If I need to deallocate any memory
	virtual void Exit() {};

protected:
	int damage; // damage this weapon can deal to enemy
};

#endif