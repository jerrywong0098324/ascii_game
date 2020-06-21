// status of the player
#ifndef PLAYER_STATUS_H
#define PLAYER_STATUS_H

enum class PlayerStatus
{
	INVALID = -1,
	NORMAL = 0, // No status effect
	SLIDING, // When player is sliding on ice block
	STUN, // get hit by stun gun || hit by spikes (take damage and get stun for x secs)
	// etc...
};

#endif