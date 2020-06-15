// Game Status
#ifndef GAMESTATE_H
#define GAMESTATE_H

enum class GameState
{
	INVALID = -1, // Used during initial value for initialisation
	MENU,  // Main Menu
	// Levels
	LEVEL_01,
	LEVEL_02,
	LEVEL_03,

	//PAUSE, // Pause screen
	EXIT, // To stop running the game
	GAME, // When game is running
	CHANGE_LEVEL, // Use this when changing level
};

#endif // !1