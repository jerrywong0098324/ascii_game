// Consist of str, colours, position
#ifndef OVERLAP_PRINT_H
#define OVERLAP_PRINT_H

#include "Colours.h"
#include "Vector2.h"

class OverlapPrint
{
public:
	OverlapPrint();
	OverlapPrint(char*& str, const int& colour = Colours::DEFAULT, const Vector2& pos = Vector2(0, 0));
	~OverlapPrint();

	void SetPrint(char*& str, const int& colour = Colours::DEFAULT, const Vector2& pos = Vector2(0, 0));

	// Setter
	void SetColour(const int& colour);
	void SetPosition(const Vector2& pos);
	void SetString(char*& str);

	// Getter
	int GetColour() const;
	Vector2 GetPosition() const;
	char* GetString() const;

private:
	int colour;
	Vector2 pos;
	char* str;
};

#endif