#include "Camera.h"

Camera::Camera(Vector2 *playerPos) : map(nullptr), playerPos(playerPos), currState(GameState::MENU)
{

}

Camera::~Camera()
{
	// don't need to deallocate memory for map (map destructor will handle it)
	// don't need to deallocate memory for playerPos either cuz no new memory was allocated to the heap
}

// print to screen according to currGameState
void Camera::Render()
{
	switch (currState)
	{
	case GameState::MENU:
		RenderMenu();
		break;
	case GameState::PAUSE:
		RenderPause();
		break;
	case GameState::GAME:
		RenderMap();
		// render dialogue box
		// render ui
		break;
	}
}

// Set map
void Camera::SetMap(char **map)
{
	this->map = map;
}

// Set current game state
void Camera::SetGameState(GameState state)
{
	currState = state;
}

//// Set player position;
//void Camera::SetPlayerPosition(Vector2 *playerPos)
//{
//	this->playerPos = playerPos;
//}

// print map onto the screen
void Camera::RenderMap()
{

}

void Camera::RenderPause()
{

}

void Camera::RenderMenu()
{

}