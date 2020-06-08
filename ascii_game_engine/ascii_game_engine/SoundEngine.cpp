#include "SoundEngine.h"
#include <iostream>

SoundEngine::SoundEngine() : engine(nullptr)
{
	CreateSoundEngine();
}

SoundEngine::~SoundEngine()
{

}

ISoundEngine *SoundEngine::GetSoundEngine() const
{
	return engine;
}

void SoundEngine::CreateSoundEngine()
{
	engine = createIrrKlangDevice();
	// don't run the program if sound engine cannot be initialise
	if (!engine)
	{
		std::cerr << "Error starting up sound engine" << std::endl;
		exit(1);
	}
}

// over-riding this to allocate relevant memory
void SoundEngine::alloc_memory()
{
	Singleton::alloc_memory();
	engine = createIrrKlangDevice();

	// don't run the program if sound engine cannot be initialise
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