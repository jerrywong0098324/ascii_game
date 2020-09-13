#include "UserInput.h"
#include <iostream>

bool UserInput::isKeyPress[222] = { false };

UserInput::UserInput()
{	

}

UserInput::~UserInput()
{

}

// Is the Key Pressed?
bool UserInput::GetKeyState(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode < UserInput::totalKeys)
		return false;
	return UserInput::isKeyPress[keyCode - 1];
}

// 	The moment when the user releases the key
bool UserInput::GetKeyUp(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode > UserInput::totalKeys)
		return false;

	if (UserInput::isKeyPress[keyCode - 1] && !GetAsyncKeyState(keyCode))
	{
		UserInput::isKeyPress[keyCode - 1] = false;
		return true;
	}
	else if (!UserInput::isKeyPress[keyCode - 1] && GetAsyncKeyState(keyCode))
		UserInput::isKeyPress[keyCode - 1] = true;

	return false;
}

// Get the key input only once
bool UserInput::GetKeyDown(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode > UserInput::totalKeys)
		return false;

	if (!UserInput::isKeyPress[keyCode - 1] && GetAsyncKeyState(keyCode))
	{
		UserInput::isKeyPress[keyCode - 1] = true;
		return true;
	}
	else if (UserInput::isKeyPress[keyCode - 1] && !GetAsyncKeyState(keyCode))
		UserInput::isKeyPress[keyCode - 1] = false;

	return false;
}

// When the user is holding down on the key
bool UserInput::GetKeyPress(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode > UserInput::totalKeys)
		return false;

	// When the key is down
	UserInput::isKeyPress[keyCode - 1] = true;
	// When the key is up
	if (UserInput::isKeyPress[keyCode - 1] && !GetAsyncKeyState(keyCode))
		UserInput::isKeyPress[keyCode - 1] = false;

	return GetAsyncKeyState(keyCode);
}

// Returns the mouse position inside the window console
Vector2 UserInput::GetMousePosition()
{
	return Mouse::GetInstance()->GetPosition();
}