#include "Pickaxe.h"
#include "Rock.h"
#include "Timer.h"

Pickaxe::Pickaxe()
{

}

Pickaxe::~Pickaxe()
{

}

// Init function
void Pickaxe::Init(Level* level)
{
	Equipment::Init(level);
	dt = 0.0f;
	pickStatus = true;
}

// Function to handle using of this item
void Pickaxe::Use()
{
	UpdatePickaxeStatus();
	UpdatePickaxe();
}

// If I need to deallocate any memory
void Pickaxe::Exit()
{

}

// Can use pickaxe every 1 sec
void Pickaxe::UpdatePickaxeStatus()
{
	dt += StopWatch::GetInstance()->GetDeltaTime();
	if (dt >= 1.0f)
		pickStatus = true;
}

// Determine whether pickaxe is in use based on map and player's position
void Pickaxe::UpdatePickaxe()
{
	if (UserInput::GetKeyDown(useButton))
	{
		if (!pickStatus) // cannot pick
			return;
		// get the position of the block based one player's direction
		int x = player->GetPosition().x + player->GetDirection().x;
		int y = player->GetPosition().y - player->GetDirection().y;
		PlayableLevels* plptr = dynamic_cast<PlayableLevels*>(level);

		Rock* rptr = dynamic_cast<Rock*>(plptr->GetBlock(Vector2(x, y)));
		if (!rptr) // no rock at pos(x,y)
			return;

		char** map = level->GetMap().GetMap();

		rptr->Interactions(); // specific interaction with rock here
		map[y][x] = rptr->GetBlockCharacter(); // replace the character
		if (rptr->Broken()) // if rock is broken, delete this block from the level
			plptr->DeleteBlock(rptr);

		Reset(); // Set only when successfully hit a rock
	}
}

// Reset pickStatus and relevant data
void Pickaxe::Reset()
{
	pickStatus = false;
	dt = 0.0f;
}