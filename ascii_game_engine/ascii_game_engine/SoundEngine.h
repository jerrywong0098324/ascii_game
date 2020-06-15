// Using irrklang's sound engine to init sounds
#define SOUND_ENGINE_H
#ifndef SOUNDENGINE_H

#include "Singleton.h"
#include "irrklang/irrKlang.h"

using namespace irrklang;

class SoundEngine : public Singleton<SoundEngine>
{
public:
	ISoundEngine *GetSoundEngine() const;
	// When exiting the level
	void StopAllAudio();

private:
	// Singleton definition
	friend class Singleton<SoundEngine>;
	SoundEngine();
	~SoundEngine();

	ISoundEngine *engine;

	// over-riding this to allocate relevant memory
	virtual void alloc_memory();
	// additional step to free engine memory
	virtual void free_memory();
};

#endif 