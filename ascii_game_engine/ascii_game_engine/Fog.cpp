#include "Fog.h"
#include "Game.h"

Fog::Fog()
{

}

Fog::~Fog()
{

}

// @param visionLength: how far the player can see from player's pos, default = 2
void Fog::Init(Map map, Vector2& playerPos, int visionLength)
{
	this->map = map;
	pos = &playerPos;
	this->visionLength = visionLength;

	// allocates new memory for my fog boolean
	InitFog();
}

void Fog::Update()
{
	UpdateVision();
}

void Fog::Exit()
{
	// deallocates memory of my fog boolean
	DeleteFog();
}

void Fog::SetVisionLength(int visionLength)
{
	this->visionLength = visionLength;
}

bool** Fog::GetFog() const
{
	return fog;
}

// update player's vision
void Fog::UpdateVision()
{
	ClearVision();
	// updating fog based on current position
	UpdateFog(pos->x, pos->y, visionLength);
}

// set tiles in fog to be all true (got fog == cannot see)
void Fog::ClearVision()
{
	for (int i = 0; i < visionPos.size(); ++i)
	{
		Vector2 vis = visionPos[i];
		fog[vis.y][vis.x] = true;
	}
	visionPos.clear(); // clear the vector
}

// updates the fog
void Fog::UpdateFog(int x, int y, int length)
{
	// at the egde of map
	if (x < 0 || x >= map.GetSizeX() || y < 0 || y >= map.GetSizeY())
		return;

	for (int i = 0; i < Game::GetInstance()->GetTotalWall(); ++i)
	{
		// if the current position is wall that cannot see through, don't allow vision beyond it
		if (map.GetCharacter(x, y) == Game::GetInstance()->GetWallList()[i])
		{
			fog[y][x] = false;
			visionPos.push_back(Vector2(x, y));
			return;
		}
	}

	// end of the loop
	if (length < 0)
		return;

	// player will be able to see the char printed at this position
	fog[y][x] = false;
	visionPos.push_back(Vector2(x, y));
	
	// call recursive function here
	UpdateFog(x - 1, y, length - 1); // goes left
	UpdateFog(x + 1, y, length - 1); // goes right
	UpdateFog(x, y - 1, length - 1); // goes up
	UpdateFog(x, y + 1, length - 1); // goes left
}

void Fog::InitFog()
{
	int x = map.GetSizeX();
	int y = map.GetSizeY();

	fog = new bool*[y]; // create row
	for (int i = 0; i < y; ++i)
	{
		fog[i] = new bool[x]; // create column	
		for (int j = 0; j < x; ++j)
			fog[i][j] = true;
	}
}

void Fog::DeleteFog()
{
	// fog not initialized
	if (!fog)
		return;

	int x = map.GetSizeX();
	int y = map.GetSizeY();

	for (int i = 0; i < y; ++i)
	{
		delete[] fog[i];
		fog[i] = nullptr;
	}
	delete[] fog;
	fog = nullptr;
}