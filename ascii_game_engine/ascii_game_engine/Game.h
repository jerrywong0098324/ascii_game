// This is where the gameplay will occur
#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "Console.h"
#include "Camera.h"
#include "Player.h"

class Game : public Singleton<Game>
{
public:

	void Init();
	void Render();
	void Update();
	void Exit();

private:
	// Singleton definition
	friend class Singleton<Game>;
	Game();
	~Game();

	// currState
	GameState currState;

	Console console;
	Camera camera;
	Player player;
};

#endif