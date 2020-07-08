/*	This class handles the printing of characters (with colors)
	Inside all render function, call this class to apply different order of printing
	Use char c = (char)250 to ignore current order, and use the previous one
*/

#ifndef RENDERER_H
#define RENDERER_H

#include "Singleton.h"
#include "Colours.h"
#include "PrintMap.h"

class Level;
class PlayableLevels;
class Renderer : public Singleton<Renderer>
{
public:

	// Add maps to be rendered onto the screen
	void Add(char** print, const int& order);
	// Calling this function only for PlayableLevels, to check if the ice block have a player on it, then render a Ice color background over the player
	void SetLevel(Level* level);

	void Init();
	void Render();
	void Exit();

	virtual void free_memory();

private:
	// Singleton definition
	friend class Singleton<Renderer>;
	Renderer();
	~Renderer();

	void AllocateMemory();
	void DeallocateMemory();

	// Set default colour for characters
	void DefaultColour();
	void Print(char*& c, const int& x, const int& y);
	void SetCursorPosition(const int& x, const int& y);

	int Ice, Boulder, Rock;

	char* print;

	PrintMap *pm;
	Level* level;
	PlayableLevels* plptr;
};

#endif