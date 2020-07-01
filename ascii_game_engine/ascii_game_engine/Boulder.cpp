#include "Boulder.h"
#include "Timer.h"
#include "Game.h"

Boulder::Boulder(int id) : Block(id)
{

}

Boulder::~Boulder()
{

}

void Boulder::Init(Player* player, Level* level)
{
	this->player = player;
	this->level = level; 
	InitBoulder();
}

// Updates the interaction between ice block and player
void Boulder::Update()
{
	Interactions();
}

// Interactions when player is on top of the block
void Boulder::Interactions()
{
	InteractBoulder();
}

// Clear any memory if neccessary
void Boulder::Exit()
{
	delete[] charBlock;
	charBlock = nullptr;
}

void Boulder::InitBoulder()
{
	charBlock = new char[1];
	charBlock[0] = (char)254;

	original_pos.Set(pos.x, pos.y);
}

void Boulder::InteractBoulder()
{
	// 1) If player is "on" the boulder, check if next block can be collided
	// 2) If next block is not a wall, move boulder to the next tile according to player's direction, then move player back back to their "previous" tile
	// 3) If next block is a wall, move player back to their "previous" tile and don't move the boulder
	// Code wise, can move the player first, check if next tile is a wall, then move/don't move the boulder

	if (pos.x != player->GetPosition().x || pos.y != player->GetPosition().y)
		return;

	// Move player back to their original position
	int x = player->GetPosition().x - player->GetDirection().x;
	int y = player->GetPosition().y + player->GetDirection().y;
	Vector2 p_pos(x, y); // Original position of the player

	// Position of the next tile
	x = player->GetPosition().x + player->GetDirection().x;
	y = player->GetPosition().y - player->GetDirection().y;

	// Set player's position to their "original" position
	player->SetPosition(p_pos);

	// Check if next tile is a wall (collidable)
	if (!AbleToPush(x, y)) // don't do anything to the boulder, if conditions are not met
	{
		level->SetMap(pos.x, pos.y, charBlock[0]);
		return;
	}

	// Set original character of this level at this position
	if (original_pos != pos)
	{
		level->CorrectMap(pos.x, pos.y);
		level->SetMap(x, y, charBlock[0]);
	}
	else
	{
		level->SetBothMap(pos.x, pos.y, ' ');
		level->SetMap(x, y, charBlock[0]);
	}

	// Set boulder's new position
	pos.Set(x, y);
}

// Check if can push
bool Boulder::AbleToPush(const int& x, const int& y)
{
	// Player trying to push the boulder of of the player map
	if (!level->WithinMap(x, y))
		return false;

	char c = level->GetCharacter(x, y);
	// if next tile is a wall, cannot collide
	if (Game::GetInstance()->DetectCollision(c)) 
		return false;

	// if next tile is also a boulder, cannot push this boulder
	c = level->GetCharacter(x, y);

	// next tile is a boulder
	if (c == charBlock[0])
		return false;

	return true;
}