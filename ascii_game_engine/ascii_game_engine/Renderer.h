/*	This class handles the printing of characters (with colors)
	Inside all render function, call this class to apply different order of printing
*/

#ifndef RENDERER_H
#define RENDERER_H

#include "Singleton.h"
#include "Colours.h"
#include "PrintMap.h"

class Renderer : public Singleton<Renderer>
{
public:

	// Add maps to be rendered onto the screen
	void Add(const char** print, const int& order);
	void Render();

private:
	// Singleton definition
	friend class Singleton<Renderer>;
	Renderer();
	~Renderer();

	PrintMap pm;
};

#endif