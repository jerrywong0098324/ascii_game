#include "OverlapPrint.h"

OverlapPrint::OverlapPrint()
{

}

OverlapPrint::OverlapPrint(char*& str, const int& colour, const Vector2& pos)
{
	SetPrint(str, colour, pos);
}

OverlapPrint::~OverlapPrint()
{

}

void OverlapPrint::SetPrint(char*& str, const int& colour, const Vector2& pos)
{
	this->colour = colour;
	this->pos = pos;
	this->str = str;
}

// Setter
void OverlapPrint::SetColour(const int& colour)
{
	this->colour = colour;
}

void OverlapPrint::SetPosition(const Vector2& pos)
{
	this->pos = pos;
}

void OverlapPrint::SetString(char*& str)
{
	this->str = str;
}

// Getter
int OverlapPrint::GetColour() const
{
	return colour;
}

Vector2 OverlapPrint::GetPosition() const
{
	return pos;
}

char* OverlapPrint::GetString() const
{
	return str;
}