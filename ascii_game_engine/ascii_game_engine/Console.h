#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <Windows.h>

class Console
{
public:
	Console(int width = 360, int height = 360);
	~Console();

private:
	int width = 360;
	int height = 360;
};

#endif