// Class to manage the current state of the game
#ifndef GAME_STATE_MANAGER_H
#define GAME_STATE_MANAGER_H

#include "Singleton.h"
#include "GameState.h"

class GameStateManager : public Singleton<GameStateManager>
{
public:
	// Getters
	GameState GetCurrentGameState() const;
	GameState GetPreviousGameState() const;

	// Setters
	void SetCurrentGameState(const GameState state);
	// Set previous state when setting current state
	void SetPreviousState(const GameState state);
	// Set both state to be the same
	void SetBothStates(const GameState state);

private:
	// Singleton definition
	friend class Singleton<GameStateManager>;
	GameStateManager();
	~GameStateManager();

	// game states
	GameState currState, prevState;
};

#endif 