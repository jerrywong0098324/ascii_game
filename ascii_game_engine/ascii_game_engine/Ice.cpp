#include "Ice.h"

Ice::Ice(int id) : Block(id)
{

}

Ice::~Ice()
{

}

void Ice::Init(Player* player)
{
	this->player = player;
	slideDir.SetZero();
}

// Updates the interaction between ice block and player
void Ice::Update()
{
	Interactions();
}

// Interactions when player is on top of the block
void Ice::Interactions()
{

}

// Clear any memory if neccessary
void Ice::Exit()
{

}