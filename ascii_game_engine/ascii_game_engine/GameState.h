// Game Status
#ifndef GAMESTATE_H
#define GAMESTATE_H

enum class GameState
{
	INVALID = 0, // Used during initial value for initialisation
	MENU,  // Main Menu
	PAUSE, // Pause screen
	EXIT, // To stop running the game
	GAME, // When game is running

	// Levels
	LEVEL_01,
};

#endif // !1