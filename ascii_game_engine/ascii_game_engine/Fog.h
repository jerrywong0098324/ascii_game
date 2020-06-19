/****************************************************************************
This class does the following:
1) Handles fog around the player
2) If player's vision is block by a 'wall', won't be able to see behind it
****************************************************************************/
#ifndef FOG_H
#define FOG_H

#include <vector>

#include "Map.h"
#include "Vector2.h"

class Fog
{
public:
	Fog();
	~Fog();

	/**************************************************************************
	example: IF visionLength = 2. P -> Player, X -> vision, | -> fog
									| | X | |
									| X X X |
									X X P X X
									| X X X |
									| | X | |
	**************************************************************************/
	/**************************************************************************
	example: IF visionLength = 3.
								  | | | X | | |
								  | | X X X | |
								  | X X X X X |
								  X X X P X X X
								  | X X X X X |
								  | | X X X | |
								  | | | X | | |
	**************************************************************************/
	// @param visionLength: how far the player can see from player's pos, default = 2
	void Init(Map map, Vector2 &playerPos, int visionLength = 2);
	void Update();
	void Exit();

	void SetVisionLength(int visionLength);
	bool** GetFog() const;

private:
	// update player's vision
	void UpdateVision();
	// set tiles in fog to be all true (got fog == cannot see)
	void ClearVision();
	// updates the fog
	void UpdateFog(int x, int y, int length);

	void InitFog();
	void DeleteFog();	

	bool** fog;
	int visionLength = 2; // default is 2

	Map map; // rendering the map
	const Vector2* pos; // player's position
	std::vector<Vector2> visionPos; // position of where the player can see
};

#endif 