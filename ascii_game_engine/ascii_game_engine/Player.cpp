#include "Player.h"
#include "UserInput.h"

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
Vector2 Player::GetPosition() const
{
	return pos;
}

// Update function to get player's input
void Player::Update()
{
	if (UserInput::GetKeyDown(KeyCode::Escape))
		GameStateManager::GetInstance()->SetCurrentGameState(GameState::EXIT);
}