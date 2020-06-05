#include "GameStateManager.h"

GameStateManager::GameStateManager() : currState(GameState::INVALID)
{
	prevState = currState;
}

GameStateManager::~GameStateManager()
{

}

GameState GameStateManager::GetCurrentGameState() const
{
	return currState;
}

GameState GameStateManager::GetPreviousGameState() const
{
	return prevState;
}

// Setters
void GameStateManager::SetCurrentGameState(const GameState state)
{
	currState = state;
}

// Set previous state when setting current state
void GameStateManager::SetPreviousState(const GameState state)
{
	prevState = state;
}

// Set both state to be the same
void GameStateManager::SetBothStates(const GameState state)
{
	currState = state;
	prevState = state;
}