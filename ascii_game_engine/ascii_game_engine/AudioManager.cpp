#include "AudioManager.h"
#include "Audio.h"

std::vector<Audio*> AudioManager::audios;

AudioManager::AudioManager()
{

}

AudioManager::~AudioManager()
{

}

void AudioManager::AddInstance(Audio *audio)
{
	audios.push_back(audio);
}

void AudioManager::FreeAll()
{
	for (int i = 0; i < audios.size(); ++i)
	{
		audios[i]->Exit();

		delete audios[i];
		audios[i] = nullptr;
	}
}