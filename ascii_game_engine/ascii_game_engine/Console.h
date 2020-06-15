#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <Windows.h>

class Console
{
public:
	Console();
	~Console();

	static void CreateConsole(int width = 360, int height = 360);
	static void ClearScreen();
	static void ClearBox();

	static COORD NewSBSize;
};

#endif