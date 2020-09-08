#include "SoundEngine.h"
#include "AudioManager.h"
#include <iostream>
#include "Error.h"

SoundEngine::SoundEngine() : engine(nullptr)
{
	alloc_memory();
}

SoundEngine::~SoundEngine()
{

}

ISoundEngine *SoundEngine::GetSoundEngine() const
{
	return engine;
}

// When exiting the level
void SoundEngine::StopAllAudio()
{
	engine->stopAllSounds();
	engine->removeAllSoundSources();
	AudioManager::FreeAll();
}

// over-riding this to allocate relevant memory
void SoundEngine::alloc_memory()
{
	engine = createIrrKlangDevice();
	// don't run the program if sound engine cannot be initialized
	if (!engine)
		Error::MyErrorExit("Error starting up sound engine");
}

// additional step to free engine memory
void SoundEngine::free_memory()
{
	engine->drop();
	Singleton::free_memory();
}