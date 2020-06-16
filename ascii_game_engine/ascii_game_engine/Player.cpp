#include "Player.h"
#include "UserInput.h"
#include "Game.h"

Player::Player()
{
	SetPlayerDir(Vector2(1, 0));

	// direction of the player
	playerChar[0] = '^';
	playerChar[1] = '>';
	playerChar[2] = 'v';
	playerChar[3] = '<';
}

Player::~Player()
{

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

// Init the player
void Player::Init(Map map, const Vector2 pos)
{
	this->map = map;
	this->pos = pos;
}

// Update function to get player's input
void Player::Update()
{
	UpdatePlayer();
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
	// Replace player's char with an empty space
	map.GetMap()[pos.y][pos.x] = ' ';

	MovePlayer();
	LimitPlayer();

	// update the new player's position onto the map
	map.GetMap()[pos.y][pos.x] = playerChar[dirChar];
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

// Collision Detection
bool Player::DetectCollision(int x_pos, int y_pos) const
{
	int sum = Game::GetInstance()->GetTotalCollide();

	// if at the edge of the map, don't need to check for collision
	if (x_pos >= map.GetSizeX() || x_pos < 0 || y_pos >= map.GetSizeY() || pos.y < 0)
		return false;

	// loop through to see if the next block ahead of player is something that cannot be collided with
	for (int i = 0; i < sum; ++i)
	{
		if (map.GetMap()[y_pos][x_pos] == Game::GetInstance()->GetCollisionList()[i])
			return true;
	}
	return false;
}