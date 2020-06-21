// Base class for blocks like Ice, Rock, Boulder, Climbing, Invisible
#ifndef	BLOCK_H
#define BLOCK_H

#include "Vector2.h"

class Block
{
public:
	Block(int id) : id(id), charBlock(nullptr) {};
	virtual ~Block() = 0 {};

	virtual void Init() {};
	// Updating the block
	virtual void Update() {};
	// Clear any memory if neccessary
	virtual void Exit() {};
	// Different blocks will have different interactions with the player
	virtual void Interactions() {};

	int GetID() const { return id; }
	Vector2 GetPosition() const { return pos; }

	char GetBlockCharacter() const { return charBlock[blockIndex]; }

	void SetPosition(const Vector2 pos) { this->pos = pos; }

protected:
	int id; // ID of the block
	char* charBlock; // store ascii character for this block (can have more than 2)
	int blockIndex = 0; // index for charBlock
	Vector2 pos; // position of the block
};

#endif