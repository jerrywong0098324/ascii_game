#include "Print.h"

int Print::Max = INT_MAX;
int Print::Min = INT_MIN;

Print::Print(const int& order, const int& colour, const char& c) : order(0), colour(0), c((char)0)
{

}

Print::~Print()
{

}

// Getter
int Print::GetOrder() const
{
	return order;
}

int Print::GetColour() const
{
	return colour;
}

char Print::GetCharacter() const
{
	return c;
}

// Setter
void Print::SetOrder(const int& order)
{
	this->order = order;
}

void Print::SetColour(const int& colour)
{
	this->colour = colour;
}

void Print::SetCharacter(const char& c)
{
	this->c = c;
}

void Print::Reset()
{
	order = Print::Min;
	colour = Colours::TBC;
	c = (char)0;
}