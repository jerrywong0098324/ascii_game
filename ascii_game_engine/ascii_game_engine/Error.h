// handles error message
#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <Windows.h>

class Error
{
public:
	Error() {};
	~Error() {};

	static void MyErrorExit(const char* s)
	{
		printf("Fatal: %s\n", s);
		exit(1);
	}
};

#endif