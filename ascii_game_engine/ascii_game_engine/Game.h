// This is where the gameplay will occur
#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "Console.h"
#include "LevelManager.h"
#include "Player.h"
#include "Timer.h"

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

	//// currState
	//GameState currState;

	float dt = 0.0f; // testing only

	//Console console;
	//Camera camera;
	Player player;
};

#endif