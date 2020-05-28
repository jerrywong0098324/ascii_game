#include "Player.h"

Player::Player()
{

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
Vector2 Player::GetPosition()
{
	return pos;
}