#include "AudioManager.h"
#include "Audio.h"

std::vector<Audio*> AudioManager::audios;

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

// add audio memory at start of level
void AudioManager::AddInstance(Audio *audio)
{
	audios.push_back(audio);
}

// free audio memory when changing level
void AudioManager::FreeAll()
{
	for (int i = 0; i < audios.size(); ++i)
	{
		if (audios[i])
		{
			audios[i]->Exit();
			delete audios[i];
			audios[i] = nullptr;
		}
	}
}