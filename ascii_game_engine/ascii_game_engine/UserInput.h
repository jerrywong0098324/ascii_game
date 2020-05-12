// Class to handle input from keyboard
#ifndef	USERINPUT_H
#define USERINPUT_H

#include <Windows.h>
#include "Singleton.h"
#include "KeyCode.h"

class UserInput : public Singleton<UserInput>
{
public:
	// Is the Key Pressed?
	bool GetKeyState(const unsigned int keyCode);
	// 	The moment when the user releases the key
	bool GetKeyUp(const unsigned int keyCode);
	// Get the key input only once
	bool GetKeyDown(const unsigned int keyCode);
	// When the user is holding down on the key
	bool GetKeyPress(const unsigned int keyCode);

private:
	// Singleton definition
	friend class Singleton<UserInput>;
	UserInput() 
	{
		//for (int i = 0; i < totalKeys; ++i)
		//	isKeyPress[i] = new bool;
	};
	~UserInput() 
	{
		//delete[] isKeyPress;
	};

	// Biggest int number of last user input data
	int totalKeys = 222;
	// Init all boolean array to be false
	bool isKeyPress[222] = { false };
};

#endif