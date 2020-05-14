// Abstract class to handle level
#ifndef	LEVEL_H
#define LEVEL_H

#include <string>

class Level
{
public:
	// mapLevel -> file directory of the map
	Level(std::string mapLevel) {};
	virtual ~Level() = 0;

	// Render function to render map
	void Render() {};

protected:
	// Map to handle the current map level
	// Sound to handle playing music?
};

#endif