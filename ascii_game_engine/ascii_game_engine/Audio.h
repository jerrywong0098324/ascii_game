/* 
	Audio class to handle audio
	List of audio file irrklang supports:
	1) RIFF WAVE (*.wav)
	2) Ogg Vorbis (*.ogg)
	3) MPEG-1 Audio Layer 3 (*.mp3)
	4) Free Lossless Audio Codec (*.flac)
	5) Amiga Modules (*.mod)
	6) Impulse Tracker (*.it)
	7) Scream Tracker 3 (*.s3d)
	8) Fast Tracker 2 (*.xm)
	* Most optimised audio file for irrklang is Ogg Vorbis (*.ogg) *

	Documentations can be found on irrklang's website
*/

#ifndef AUDIO_H
#define AUDIO_H

#include "SoundEngine.h"

class Audio
{
public:	
	Audio(const char *audioFile); // eg. "../Sound/soundFile.mp3"
	/*
		@param-> soundFile: file directory of the sound
		@param-> defaultVolume: default volume of audio
		@param-> playLooped: looping audio?
		@param-> startPaused: starting the audio paused
	*/
	Audio(const char* audioFile, float defaultVolume = 1.0f, bool playLooped = false, bool startPaused = false);
	~Audio();

	// change the current sound to another sound
	void SetAudio(const char *audioFile, float defaultVolume = 1.0f);

	/***************************************
			   Function for audios
	***************************************/
	// Play the sound
	void Play();
	// Pause and Unpause the sound
	void Pause();
	// Stop the sound from playing
	void Stop();
	// Set the volume of the sound
	void SetVolume(float volume);
	// Check if the sound is finish
	bool IsFinished() const;

	// free memory
	void Exit();

private:
	// sound to be played
	ISound *sound;
	// source to the sound
	ISoundSource *soundSource; // need not to deallocate the memory

	bool isPause;
	bool playLooped, startPaused;
};

#endif 