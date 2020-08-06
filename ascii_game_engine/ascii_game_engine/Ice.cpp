#include "Ice.h"
#include "Game.h"
#include "Renderer.h"

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
	
	plptr = dynamic_cast<PlayableLevels*>(level);

	blockOnIce = (char)0;
	blockOrder = 10;

	InitIce();
}

// Updates the interaction between ice block and player
void Ice::Update()
{
	UpdateBlockOnIce();
	Interactions();
}

// Render player's and any block foreground with ice background
void Ice::Render()
{
	RenderPlayer();
	RenderBlock();
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

// Returns the block on the ice
char Ice::GetBlockOnIce() const
{
	return blockOnIce;
}

void Ice::InitIce()
{
	Block::Init();
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
	Vector2 p_pos(x, y); // position of the next tile, also new position for player if conditions are met

	// First check checks if there is a boulder like block so that it will acts as a "collision" detection
	// param p_pos checks if the next position is a not a "wall" but cannot be collided with (eg. Boulder)
	if (blockOnIce || plptr->GetNotThisBlock(p_pos, charBlock[blockIndex]) || !level->WithinMap(x, y) || !AbleToSlide(x, y))
	{
		player->SetPlayerStatus(PlayerStatus::NORMAL);
		return;
	}

	// Sliding
	level->CorrectMap(player->GetPosition().x, player->GetPosition().y);
	// Set new player position
	if (player->CanSlide())
		player->SetPosition(p_pos);
}

// Boolean to check if player is at the end of the ice block, collided with a wall or within the edge of the map
bool Ice::AbleToSlide(const int& x, const int& y)
{
	char c = level->GetCharacter(x, y);

	// Checks for collision and if the next tile is the end
	if (Game::GetInstance()->DetectCollision(c))
		return false;
	// if next tile is not ice, cannot slide
	if (level->GetCharacter(x, y) != charBlock[0])
	{
		level->CorrectMap(player->GetPosition().x, player->GetPosition().y);
		
		player->SetPosition(Vector2(x, y));
		return false;
	}

	return true; // next tile is a ice block, and it's within the playing map
}

// Updates if there's any other blocks on the ice
void Ice::UpdateBlockOnIce()
{
	blockOnIce = plptr->GetNotThisBlock(pos, charBlock[blockIndex]);
}

// Render player
void Ice::RenderPlayer()
{
	if (pos.x != player->GetPosition().x || pos.y != player->GetPosition().y)
		return;

	int colour = Colours::BLACK | Colours::BG_CYAN;
	int x_buffer = plptr->GetXBuffer();
	int y_buffer = plptr->GetYBuffer();

	Renderer::GetInstance()->Add(pos.x - x_buffer, pos.y - y_buffer, blockOrder, colour, player->GetPlayerChar());
}

// Render any block that will is on the ice
void Ice::RenderBlock()
{
	if (!blockOnIce)
		return;

	int colour = Renderer::GetInstance()->GetColours(blockOnIce) | Colours::BG_CYAN;
	int x_buffer = plptr->GetXBuffer();
	int y_buffer = plptr->GetYBuffer();

	Renderer::GetInstance()->Add(pos.x - x_buffer, pos.y - y_buffer, blockOrder, colour, blockOnIce);
}