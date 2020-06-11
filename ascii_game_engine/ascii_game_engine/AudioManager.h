// Audio Manager to call all sound's drop (free-ing memory)
#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <vector>

class Audio;
class AudioManager
{
public:
	static void AddInstance(Audio *audio);
	static void FreeAll();

private:
	AudioManager();
	~AudioManager();

	AudioManager(AudioManager const&) = delete;
	AudioManager& operator=(AudioManager const&) = delete;
	AudioManager(AudioManager&&) = delete;
	AudioManager& operator=(AudioManager&&) = delete;

	static std::vector<Audio*> audios;
};

#endif