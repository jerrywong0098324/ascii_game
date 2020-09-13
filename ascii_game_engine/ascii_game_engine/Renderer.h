/*	This class handles the printing of characters (with colors)
	Inside all render function, call this class to apply different order of printing
	Use char c = (char)250 to ignore current order, and use the previous one
*/

#ifndef RENDERER_H
#define RENDERER_H

#include "MemoryLeak.h"
#include "Singleton.h"
#include "Print.h"

class Level;
class PlayableLevels;
class Renderer : public Singleton<Renderer>
{
public:
	// Replace the current pt data to be used for rendering
	void Add(const int& x, const int& y, const Print& pt);
	void Add(const int& x, const int& y, const int& order, const int& colour, char c);

	//// Add maps to be rendered onto the screen
	//void Add(char** print, const int& order);
	//// Add special cases rendering to be rendered over the original
	//void AddOverlap(const OverlapPrint& print);

	// Calling this function only for PlayableLevels, to check if the ice block have a player on it, then render a Ice color background over the player
	void SetLevel(Level* level);
	// Get Colours based on the char
	int GetColours(const char& c);
	// Get temp string
	char* GetTemporaryString() const;

	void Init();
	void Render();
	void Exit();

	virtual void free_memory();

private:
	// Singleton definition
	friend class Singleton<Renderer>;
	Renderer();
	~Renderer();

	//// Normal rendering
	//void RenderNormal();
	//// Special render conditions, Eg: Ice
	//void RenderOverlap();

	void AllocateMemory();
	void DeallocateMemory();

	// Set default colour for characters
	void DefaultColour();
	void PrintMap();
	void PrintMap(char*& str, const int& x, const int& y);
	void PrintMap(char*& str, const int& x, const int& y, const int& colours);
	void SetCursorPosition(const int& x, const int& y);

	void ResetPrint();

	int ice, boulder, rock;

	char* print;
	char* temp; // used outside of this class

	//PrintMap *pm;
	Print** pt;
	Level* level;
	PlayableLevels* plptr;

	//std::vector<OverlapPrint> ol_prints;
};

#endif