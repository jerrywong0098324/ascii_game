#include "UserInput.h"

// Is the Key Pressed?
bool UserInput::GetKeyState(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode < totalKeys)
		return false;
	return isKeyPress[keyCode - 1];
}

// 	The moment when the user releases the key
bool UserInput::GetKeyUp(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode > totalKeys)
		return false;

	if (isKeyPress[keyCode - 1] && !GetAsyncKeyState(keyCode))
	{
		isKeyPress[keyCode - 1] = false;
		return true;
	}
	else if (!isKeyPress[keyCode - 1] && GetAsyncKeyState(keyCode))
		isKeyPress[keyCode - 1] = true;

	return false;
}

// Get the key input only once
bool UserInput::GetKeyDown(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode > totalKeys)
		return false;

	if (!isKeyPress[keyCode - 1] && GetAsyncKeyState(keyCode))
	{
		isKeyPress[keyCode - 1] = true;
		return true;
	}
	else if (isKeyPress[keyCode - 1] && !GetAsyncKeyState(keyCode))
		isKeyPress[keyCode - 1] = false;

	return false;
}

// When the user is holding down on the key
bool UserInput::GetKeyPress(const unsigned int keyCode)
{
	if (keyCode == 0 || keyCode > totalKeys)
		return false;

	// if(isKeyPress[keyCode - 1] && GetAsyncKeyState(keyCode))
	isKeyPress[keyCode - 1] = true;
	return GetAsyncKeyState(keyCode);
}