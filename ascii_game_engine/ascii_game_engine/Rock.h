// Player needs to have a pickaxe in order to break down a rock
#ifndef ROCK_H
#define ROCK_H

#include "Block.h"

class Rock : public Block
{
public:
	Rock(int id);
	virtual ~Rock();

	virtual void Init();
	// Different blocks will have different interactions with the player (Sort of a Update function)
	virtual void Interactions();
	// Clear and memory if neccessary
	virtual void Exit();

	// is the rock broken?
	bool Broken() const;

private:
	void InitRock();
	void InteractRock();

	bool isBroken;
};

#endif