#include "Ice.h"
#include "Game.h"

Ice::Ice(int id) : Block(id)
{

}

Ice::~Ice()
{

}

void Ice::Init(Player* player, Level* level)
{
	this->player = player;
	this->level = level;
	InitIce();
}

// Updates the interaction between ice block and player
void Ice::Update()
{
	Interactions();
}

// Interactions when player is on top of the block
void Ice::Interactions()
{
	InteractIce();
}

// Clear any memory if neccessary
void Ice::Exit()
{
	delete[] charBlock;
	charBlock = nullptr;
}

void Ice::InitIce()
{
	charBlock = new char[1];
	charBlock[0] = (char)219;
}

// Player's interactions with ice
void Ice::InteractIce()
{
	// Sort of "lock" the player, don't allow it to move anywhere instead of changing it's character
	if (pos.x != player->GetPosition().x || pos.y != player->GetPosition().y)
		return;

	player->SetPlayerStatus(PlayerStatus::SLIDING); // different movements
	// move player to the next tile based on the initial 
	int x = player->GetPosition().x + player->GetDirection().x;
	int y = player->GetPosition().y - player->GetDirection().y;
	Vector2 pos(x, y);

	// Replace prev char with ice block
	level->GetMap().GetMap()[player->GetPosition().y][player->GetPosition().x] = charBlock[0];
	// Set new player position
	player->SetPosition(pos);

	// if cannot slide..
	if (!AbleToSlide(x, y))
		player->SetPlayerStatus(PlayerStatus::NORMAL);
}

// Boolean to check if player is at the end of the ice block, collided with a wall or within the edge of the map
bool Ice::AbleToSlide(int x, int y)
{
	// Checks for collision and if the next tile is the end
	if (DetectCollision(x, y))
		return false;
	// if next tile is not ice, cannot slide
	if (level->GetMap().GetMap()[y][x] != charBlock[0])
		return false;

	return true; // next tile is a ice block, and it's within the playing map
}

// Detect collision
bool Ice::DetectCollision(int x, int y)
{
	int sum = Game::GetInstance()->GetTotalCollide();

	// if at the edge of the map, don't need to check for collision
	if (x >= level->GetMap().GetSizeX() || x <= 0 || y >= level->GetMap().GetSizeY() || y <= 0)
		return false;

	// loop through to see if the next block ahead of player is something that cannot be collided with
	for (int i = 0; i < sum; ++i)
	{
		if (level->GetMap().GetMap()[y][x] == Game::GetInstance()->GetCollisionList()[i])
			return true;
	}
	return false;
}