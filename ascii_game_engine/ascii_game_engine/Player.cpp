#include "Player.h"
#include "UserInput.h"
#include "Game.h"
#include "InventoryManager.h"
//#include <conio.h> // _getch()

Player::Player()
{
	SetPlayerDir(Vector2(1, 0));

	// direction of the player
	playerChar[0] = '^'; // up
	playerChar[1] = '>'; // right
	playerChar[2] = 'v'; // down
	playerChar[3] = '<'; // left
}

Player::~Player()
{

}

// Init the player
void Player::Init(Level* level, const Vector2 pos)
{
	this->map = level->GetMap();
	this->pos = pos;
	LimitPos();

	// Inventory and items
	curr_item_index = 0;
	min_item_index = max_item_index = 0;
	InitInventory(level);
	currItem = inventory.GetItem(curr_item_index);

	// PlayerStatus
	currState = PlayerStatus::NORMAL;
}

// Update function to get player's input
void Player::Update()
{
	UpdatePlayer();
	UpdateItem();
}

// Render Inventory
void Player::Render(char** print)
{

}

// Clear any necessary memory allocation
void Player::Exit()
{
	inventory.Exit();
}

// Return the address of the position
Vector2 &Player::GetRefPosition()
{
	return pos;
}

// Return Player's Position
Vector2 Player::GetPosition() const
{
	return pos;
}

// Return Player's Direction
Vector2 Player::GetDirection() const
{
	return dir;
}

// Return Player's current status
PlayerStatus Player::GetPlayerStatus() const
{
	return currState;
}

void Player::SetPosition(const Vector2 pos)
{
	this->pos = pos;
}

void Player::SetMap(Map map)
{
	this->map = map;
}

void Player::SetPlayerDir(const Vector2 dir)
{
	int res = dir.x * 2 + dir.y * 3;	
	switch (res) // fails to update player's dir if somehow the dir set where both x and y is non-zero
	{
	case 2: // x = 1 (right)
		SetDirectionChar(1);
		break;
	case -2: // x = -1 (left)
		SetDirectionChar(3);
		break;
	case 3: // y = 1 (down)
		SetDirectionChar(2);
		break;
	case -3: // y = -1 (up)
		SetDirectionChar(0);
		break;
	}
}

void Player::SetPlayerStatus(const PlayerStatus state)
{
	currState = state;
}

// Add item into inventory
void Player::AddItem(Item* item)
{
	// max_item_index + 1 to reflect the size inside inventory
	if (max_item_index + 1 >= max_item_shown) // allow only 'max_item_shown number' of items in the inventory
		return;
	max_item_index = inventory.AddItem(item) - 1;
	curr_item_index = max_item_index; // let player hold on to the new item
	currItem = inventory.GetItem(curr_item_index);
}

void Player::LimitPos()
{
	// Limit X
	if (pos.x >= map.GetSizeX())
		pos.x = map.GetSizeX() - 1;
	else if (pos.x <= 0)
		pos.x = 0;

	// Limit Y
	if (pos.y >= map.GetSizeY())
		pos.y = map.GetSizeY() - 1;
	else if (pos.y <= 0)
		pos.y = 0;
}

// Set the dir char and finally the direction of where the player is facing
void Player::SetDirectionChar(const int dirChar)
{
	this->dirChar = dirChar;
	switch (dirChar)
	{
	case 0:
		dir.Set(0, 1);
		break;
	case 1:
		dir.Set(1, 0);
		break;
	case 2:
		dir.Set(0, -1);
		break;
	case 3:
		dir.Set(-1, 0);
		break;
	}
}

// Updates the player input
void Player::UpdatePlayer()
{
	switch (currState)
	{
		case PlayerStatus::NORMAL: // Normal player movements
		{
			// Replace player's char with an empty space
			map.GetMap()[pos.y][pos.x] = ' ';

			MovePlayer();
			LimitPlayer();

			// update the new player's position onto the map
			map.GetMap()[pos.y][pos.x] = playerChar[dirChar];
			break;
		}
		case PlayerStatus::SLIDING: // interactions with ice block
		{
			Sliding();
			//// update the new player's position onto the map
			//map.GetMap()[pos.y][pos.x] = playerChar[dirChar];
			break;
		}
	}
}

// Moves the player and check for collision
void Player::MovePlayer()
{
	if (UserInput::GetKeyPress(KeyCode::UpArrow))
	{
		if (!DetectCollision(pos.x, pos.y - 1))
			--pos.y;
		SetPlayerDir(Vector2(0, -1));
		// play sound based on the tile player is walking?
	}
	else if (UserInput::GetKeyPress(KeyCode::RightArrow))
	{
		if (!DetectCollision(pos.x + 1, pos.y))
			++pos.x;
		SetPlayerDir(Vector2(1, 0));
	}
	else if (UserInput::GetKeyPress(KeyCode::DownArrow))
	{
		if (!DetectCollision(pos.x, pos.y + 1))
			++pos.y;
		SetPlayerDir(Vector2(0, 1));
	}
	else if (UserInput::GetKeyPress(KeyCode::LeftArrow))
	{
		if (!DetectCollision(pos.x - 1, pos.y))
			--pos.x;
		SetPlayerDir(Vector2(-1, 0));
	}
}

// Make sure player isn't going out of bounds
void Player::LimitPlayer()
{
	LimitPos();
}

// Collision Detection
bool Player::DetectCollision(int x_pos, int y_pos) const
{
	int sum = Game::GetInstance()->GetTotalCollide();

	// if at the edge of the map, don't need to check for collision
	if (x_pos >= map.GetSizeX() || x_pos <= 0 || y_pos >= map.GetSizeY() || y_pos <= 0)
		return false;

	// loop through to see if the next block ahead of player is something that cannot be collided with
	for (int i = 0; i < sum; ++i)
	{
		if (map.GetMap()[y_pos][x_pos] == Game::GetInstance()->GetCollisionList()[i])
			return true;
	}
	return false;
}

// Initialize inventory from save file
void Player::InitInventory(Level* level)
{
	std::vector<Item*> items = InventoryManager::InitInventory(level, this);
	for (int i = 0; i < items.size(); ++i) // add into inventory
		inventory.AddItem(items[i]);
}

// Updates item the player is holding
void Player::UpdateItem()
{
	if (!currItem) // player not holding anything
		return;
	ChangeItem();
	NextItem();
	UpdateItemInteraction();
}

// Update item's interaction
void Player::UpdateItemInteraction()
{
	currItem->Use();
}

// Change item using 1 - 5
void Player::ChangeItem()
{
	int prev_item_index = curr_item_index;
	if (UserInput::GetKeyDown(KeyCode::One))
		curr_item_index = 0;
	else if (UserInput::GetKeyDown(KeyCode::Two))
		curr_item_index = 1;
	else if (UserInput::GetKeyDown(KeyCode::Three))
		curr_item_index = 2;
	else if (UserInput::GetKeyDown(KeyCode::Four))
		curr_item_index = 3;
	else if (UserInput::GetKeyDown(KeyCode::Five))
		curr_item_index = 4;

	// if curr_item_index >= number of item in inventory, player will just be holding what he was already holding
	if (curr_item_index >= max_item_index)
		curr_item_index = prev_item_index;

	currItem = inventory.GetItem(curr_item_index);
}

// Change item using q and e
void Player::NextItem()
{
	// prev item
	if (UserInput::GetKeyDown(KeyCode::Q))
		--curr_item_index;
	else if (UserInput::GetKeyDown(KeyCode::E))
		++curr_item_index;

	// wrap around
	if (curr_item_index > max_item_index)
		curr_item_index = min_item_index;
	else if (curr_item_index < min_item_index)
		curr_item_index = max_item_index;

	// set the item player is holding
	currItem = inventory.GetItem(curr_item_index);
}

/*******************************************************************
						SLIDING FEATURES
		  Behaviour when player interacts with ice blocks
*******************************************************************/
void Player::Sliding()
{
	if (UserInput::GetKeyDown(KeyCode::UpArrow))
		dirChar = 0;
	else if (UserInput::GetKeyDown(KeyCode::RightArrow))
		dirChar = 1;
	else if (UserInput::GetKeyDown(KeyCode::DownArrow))
		dirChar = 2;
	else if (UserInput::GetKeyDown(KeyCode::LeftArrow))
		dirChar = 3;
}
// ******************************************************************