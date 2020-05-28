// Class to handle input from keyboard
#ifndef	USERINPUT_H
#define USERINPUT_H

#include <Windows.h>
//#include "Singleton.h"
#include "KeyCode.h"

class UserInput /*: public Singleton<UserInput>*/
{
public:
	UserInput();
	~UserInput();

	// Is the Key Pressed?
	static bool GetKeyState(const unsigned int keyCode);
	// 	The moment when the user releases the key
	static bool GetKeyUp(const unsigned int keyCode);
	// Get the key input only once
	static bool GetKeyDown(const unsigned int keyCode);
	// When the user is holding down on the key
	static bool GetKeyPress(const unsigned int keyCode);

private:
	//// Singleton definition
	//friend class Singleton<UserInput>;
	//UserInput() 
	//{
	//	//for (int i = 0; i < totalKeys; ++i)
	//	//	isKeyPress[i] = new bool;
	//};
	//~UserInput() 
	//{
	//	//delete[] isKeyPress;
	//};

	// Biggest int number of last user input data
	static const int totalKeys = 222;
	// Init all boolean array to be false
	static bool isKeyPress[222];
};

#endif