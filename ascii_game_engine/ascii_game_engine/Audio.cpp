#include "Audio.h"
#include "AudioManager.h"

Audio::Audio() : sound(nullptr), soundSource(nullptr), isPause(false), playLooped(false), startPaused(false), track(false)
{

}

Audio::~Audio()
{

}

void Audio::Init(const char* audioFile, float defaultVolume, bool playLooped, bool startPaused, bool track)
{
	this->playLooped = playLooped;
	this->startPaused = startPaused;
	this->track = track;

	SetAudio(audioFile, defaultVolume);
	AudioManager::AddInstance(this);
}

// change the current sound to another sound
void Audio::SetAudio(const char *audioFile, float defaultVolume)
{
	soundSource = SoundEngine::GetInstance()->GetSoundEngine()->addSoundSourceFromFile(audioFile);
	soundSource->setDefaultVolume(defaultVolume);
}

/***************************************
		   Function for audios
***************************************/
// Play the sound
void Audio::Play()
{
	sound = SoundEngine::GetInstance()->GetSoundEngine()->play2D(soundSource, playLooped, startPaused, track);
}

// Pause and Unpause the sound
void Audio::Pause()
{
	if (!sound) // not tracking the audio
		return;
	isPause = !isPause;
	sound->setIsPaused(isPause);
}

// Stop the sound from playing
void Audio::Stop()
{
	if (!sound)
		return;
	sound->stop();
}

// Set the volume of the sound
void Audio::SetVolume(float volume)
{
	if (!sound)
		return;
	sound->setVolume(volume);
}

// Check if the sound is finish
bool Audio::IsFinished() const
{
	if (!sound)
		return false;
	return sound->isFinished();
}

// Set the sound to looping
void Audio::SetLoop(bool loop)
{
	playLooped = loop;
}

// free memory
void Audio::Exit()
{
	if (sound)
	{
		sound->drop();
		sound = nullptr;
	}
}