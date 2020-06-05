// Using camera class to handle what to print onto screen
#ifndef CAMERA_H
#define CAMERA_H

#include <iostream> // for std::cout 
#include "LevelManager.h"
#include "Vector2.h"

class Camera
{
public:
	Camera(Vector2 *playerPos = nullptr);
	~Camera();

	// print to screen according to currGameState
	void Render();
	// Set map
	void SetMap(char **map);
	// Set current game state
	void SetGameState(GameState state);
	//// Set player position;
	//void SetPlayerPosition(Vector2 *playerPos);

private:
	// reference to the map
	char **map;
	// Player's position
	const Vector2 *playerPos;
	// curr game state
	GameState currState;

	// print map onto the screen
	void RenderMap();
	void RenderPause();
	void RenderMenu();
};

#endif // !1