// This is where the gameplay will occur
#ifndef GAME_H
#define GAME_H

#include "Singleton.h"
#include "Console.h"

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

	Console console;
};

#endif