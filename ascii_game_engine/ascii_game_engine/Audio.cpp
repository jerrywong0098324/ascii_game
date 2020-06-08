#include "Audio.h"

Audio::Audio(const char *audioFile) : sound(nullptr), soundSource(nullptr), isPause(false), playLooped(false), startPaused(false)
{
	SetAudio(audioFile);
}

Audio::Audio(const char* audioFile, float defaultVolume, bool playLooped, bool startPaused) : sound(nullptr), soundSource(nullptr), isPause(startPaused), playLooped(playLooped), startPaused(startPaused)
{
	SetAudio(audioFile, defaultVolume);
}

Audio::~Audio()
{

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
	// always track the sound
	sound = SoundEngine::GetInstance()->GetSoundEngine()->play2D(soundSource, playLooped, startPaused, true);
}

// Pause and Unpause the sound
void Audio::Pause()
{
	isPause = !isPause;
	sound->setIsPaused(isPause);
}

// Stop the sound from playing
void Audio::Stop()
{
	sound->stop();
}

// Set the volume of the sound
void Audio::SetVolume(float volume)
{
	sound->setVolume(volume);
}

// Check if the sound is finish
bool Audio::IsFinished() const
{
	return sound->isFinished();
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