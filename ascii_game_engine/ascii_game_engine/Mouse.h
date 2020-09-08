// Handles 
#ifndef	MOUSE_H
#define MOUSE_H

#include "Error.h"
#include "Vector2.h"
#include "Singleton.h"

class Application;
class Mouse : public Singleton<Mouse>
{
	friend class Application;
public:
	Vector2 GetPosition(); // Get's mouse position

private:
	friend class Singleton<Mouse>;
	Mouse();
	~Mouse();

	void Init();
	void Update();
	void Exit();

	Vector2 position;
};

#endif