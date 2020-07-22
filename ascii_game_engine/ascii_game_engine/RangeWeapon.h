// No reloading time on weapons, limiting fact is limited ammo
#ifndef RANGE_WEAPON_H
#define RANGE_WEAPON_H

#include "Weapon.h"

class RangeWeapon : public Weapon
{
public:
	RangeWeapon() :curr_ammo(0), max_ammo(0), shooting_rate(0.0f) {};
	virtual ~RangeWeapon() = 0 {};

	// To init the item
	virtual void Init(int curr_ammo, int max_ammo, float shooting_rate) { this->curr_ammo = curr_ammo; this->max_ammo = max_ammo; this->shooting_rate = shooting_rate; };
	// Function to handle using of this item
	virtual void Use() {};
	// If I need to deallocate any memory
	virtual void Exit() {};

protected:
	int curr_ammo; // amount of ammo that can be used
	int max_ammo; // maximum amount of ammo that player can have
	float shooting_rate; // the rate of which the gun can shoot
};

#endif