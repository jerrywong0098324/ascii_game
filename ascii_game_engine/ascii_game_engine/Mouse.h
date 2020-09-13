// Handles mouse input
#ifndef	MOUSE_H
#define MOUSE_H

#include "Error.h"
#include "Vector2.h"
#include "Singleton.h"

class Application;
class UserInput;
class Mouse : public Singleton<Mouse>
{
	friend class Application;
	friend class UserInput;
private:
	friend class Singleton<Mouse>;
	Mouse();
	~Mouse();

	virtual void free_memory();

	// Kick off a worker thread to run update loop individually
	void Init();
	// Updates the mouse position whenever there is a mouse input from the user
	void Update();
	void Exit();

	Vector2 GetPosition(); // Get's mouse position
	Vector2 position;
};

#endif