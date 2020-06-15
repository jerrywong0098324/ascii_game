#include "SoundEngine.h"
#include "AudioManager.h"
#include <iostream>

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
	AudioManager::FreeAll();
}

// over-riding this to allocate relevant memory
void SoundEngine::alloc_memory()
{
	engine = createIrrKlangDevice();
	// don't run the program if sound engine cannot be initialized
	if (!engine)
	{
		std::cerr << "Error starting up sound engine" << std::endl;
		exit(1);
	}
}

// additional step to free engine memory
void SoundEngine::free_memory()
{
	engine->drop();
	Singleton::free_memory();
}