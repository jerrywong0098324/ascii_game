#include "Rock.h"

Rock::Rock(int id) : Block(id)
{

}

Rock::~Rock()
{

}

void Rock::Init()
{
	InitRock();
}

// Different blocks will have different interactions with the player (Sort of a Update function)
void Rock::Interactions()
{
	InteractRock();
}

// is the rock broken?
bool Rock::Broken() const
{
	return isBroken;
}

// Clear and memory if neccessary
void Rock::Exit()
{
	delete[] charBlock;
	charBlock = nullptr;
}

void Rock::InitRock()
{
	Block::Init();
	// 3 characters for the rock block
	charBlock = new char[3];
	charBlock[0] = (char)178; // Before picking the rock
	charBlock[1] = (char)177; // After picking the rock once
	charBlock[2] = ' ';		  // Breaking the rock

	isBroken = false;
}

void Rock::InteractRock()
{
	++blockIndex;
	if (blockIndex >= 2)
		isBroken = true;
}