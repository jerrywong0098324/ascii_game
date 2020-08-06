// Using this to print char onto the screen with colours
#ifndef PRINT_H
#define PRINT_H

#include "Colours.h"
#include "MemoryLeak.h"

class Print
{
public:
	Print(const int& order = 0, const int& colour = Colours::TBC, const char& c = (char)0);
	~Print();

	// Static variables
	static int Max;
	static int Min;

	// Getter
	int GetOrder() const;
	int GetColour() const;
	char GetCharacter() const;

	// Setter
	void SetOrder(const int& order);
	void SetColour(const int& colour);
	void SetCharacter(const char& c);

	void Reset();

private:
	int order; // Smaller numbers will be overlapped by bigger numbers
	int colour; // used to determine what colour it will show on this text block
	char c; // characters to be printed out
};

#endif