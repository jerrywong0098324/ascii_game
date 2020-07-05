// Base class for blocks like Ice, Rock, Boulder, Climbing, Invisible
#ifndef	BLOCK_H
#define BLOCK_H

#include "Vector2.h"

class Block
{
public:
	Block(int id) : id(id) {};
	virtual ~Block() = 0 {};

	virtual void Init() { blockIndex = 0; };
	// Updating the block
	virtual void Update() {};
	// Clear any memory if neccessary
	virtual void Exit() {};
	// Different blocks will have different interactions with the player
	virtual void Interactions() {};

	int GetID() const { return id; }
	Vector2 GetPosition() const { return pos; }

	char GetBlockCharacter() const { return charBlock[blockIndex]; }

	void SetPosition(const Vector2& pos) { this->pos = pos; }
	void SetBlockType(const char* blockType) { this->blockType = blockType; }

protected:
	int id; // ID of the block
	char* charBlock; // store ascii character for this block (can have more than 2)
	const char* blockType;
	int blockIndex; // index for charBlock
	Vector2 pos; // position of the block
};

#endif