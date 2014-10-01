// SoundManager.h
#pragma once
#include <SFML\Audio.hpp>
#include <string>


struct SoundsStruct
{
	std::string path;
	sf::Sound* soundData;
	sf::SoundBuffer* buffer;
	~SoundsStruct()
	{
		delete soundData;
		delete buffer;

		soundData = nullptr;
		buffer = nullptr;
	}
};
struct MusicStruct
{
	std::string path;
	sf::Music* soundHandle;
};


class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	bool Initialize(std::string path);
	void PlaySound(std::string path);
	void PlayMusic(std::string path);

	void StopSound();
	void StopMusic();
	void SetMusicVolume(int value);
	void SetSoundVolume(int value);
	int GetMusicVolume();
	int GetSoundVolume();
	void PauseSound();
	std::vector<SoundsStruct> ReturnSound();
	void MuteSound();
	void MuteMusic();

private:
	std::vector<SoundsStruct> m_SoundBank;
	std::vector<MusicStruct> m_MusicBank;
	int m_SoundVolume;
	int m_MusicVolume;
	std::string m_directory;
	void AddSound(std::string path);
	void AddMusic(std::string path);
	int OldVolMusic, OldVolSound;
	bool b_MuteM, b_MuteS;

};

