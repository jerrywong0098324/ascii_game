#include "Pickaxe.h"
#include "Rock.h"

Pickaxe::Pickaxe()
{

}

Pickaxe::~Pickaxe()
{

}

// Function to handle using of this item
void Pickaxe::Use()
{
	UpdatePickaxe();
}

// If I need to deallocate any memory
void Pickaxe::Exit()
{

}

// Determine whether pickaxe is in use based on map and player's position
void Pickaxe::UpdatePickaxe()
{
	if (UserInput::GetKeyDown(useButton))
	{
		// get the position of the block based one player's direction
		int x = player->GetPosition().x + player->GetDirection().x;
		int y = player->GetPosition().y + player->GetDirection().y;
		PlayableLevels* plptr = dynamic_cast<PlayableLevels*>(level);

		Rock* rptr = dynamic_cast<Rock*>(plptr->GetBlock(Vector2(x, y)));
		if (!rptr) // no rock at pos(x,y)
			return;

		rptr->Interactions(); // specific interaction with rock here
		map[y][x] = rptr->GetBlockCharacter(); // replace the character
		if (rptr->Broken()) // if rock is broken, delete this block from the level
			plptr->DeleteBlock(rptr);
	}
}