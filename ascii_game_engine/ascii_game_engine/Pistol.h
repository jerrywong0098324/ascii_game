#ifndef PISTOL_H
#define PISTOL_H

#include "RangeWeapon.h"

class Pistol : public RangeWeapon
{
public:
	Pistol();
	virtual ~Pistol();

	// To init the item
	virtual void Init();
	// Function to handle using of this item
	virtual void Use();
	// If I need to deallocate any memory
	virtual void Exit();
};

#endif