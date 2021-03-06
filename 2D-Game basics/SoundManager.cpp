// SoundManager.cpp
#include "SoundManager.h"
#include "DebugManager.h"
#include <sstream>
#include <iostream>


SoundManager::SoundManager()
{
	int m_SoundVolume = 100;
	int m_MusicVolume = 100;
	m_SoundBank.reserve(2);
	m_MusicBank.reserve(2);
	b_MuteM = false;
	b_MuteS = false;
}

SoundManager::~SoundManager()
{ 
	for (SoundsStruct sound : m_SoundBank)
	{
		sound.~SoundsStruct();
	}
}

void SoundManager::PlaySound(std::string path)
{
	for (SoundsStruct sound : m_SoundBank)
	{
		if (sound.path == path)
		{
			sound.soundData->play();
			sound.soundData->setVolume(m_SoundVolume);
			//			cout << "Sound was found, playing : " << path << endl;

			return;
		}
	}
	//cout << "Sound not found, adding sound : " << path << endl;
	AddSound(path);
	PlaySound(path);
}

void SoundManager::PlayMusic(std::string path)
{

	if (m_MusicBank.size() > 0)
	{
		for (MusicStruct music : m_MusicBank)
		{
			if (music.path == path)
			{

				music.soundHandle->play();
				music.soundHandle->setVolume(m_MusicVolume);
				music.soundHandle->setLoop(true);
				//cout << "Music was found, playing : " << path << endl;
				return;
			}


		}
	}

	std::stringstream stream;

	stream << "[" << __FILE__ << ":" << __LINE__ << "] Music not found, adding sound : " << path;

	DebugManager::GetInstance().CreateDebugMessage(stream.str(), DebugManager::LOG);
	
	//std::cout << "[" << __FILE__ << ":" << __LINE__ << "] Music not found, adding sound : " << path << std::endl;
	AddMusic(path);
	PlayMusic(path);
}

std::vector<SoundsStruct> SoundManager::ReturnSound()
{
	return m_SoundBank;
}



void SoundManager::StopSound()
{

}

bool SoundManager::Initialize(std::string directory)
{
	m_directory = directory;
	

	return true;
}

void SoundManager::SetMusicVolume(int value)
{
	m_SoundVolume = value;
	for (MusicStruct music : m_MusicBank)
	{
		music.soundHandle->setVolume(value);
	}
}

void SoundManager::SetSoundVolume(int value)
{
	m_MusicVolume = value;
	m_SoundVolume = value;
	for (SoundsStruct sound : m_SoundBank)
	{
		sound.soundData->setVolume(value);
	}
}


int SoundManager::GetMusicVolume()
{
	return m_MusicVolume;
}

int SoundManager::GetSoundVolume()
{
	return m_SoundVolume;
}


void SoundManager::PauseSound()
{

}

void SoundManager::AddSound(std::string path)// Memleak
{

	SoundsStruct soundstruct;
	sf::Sound* thesound = new sf::Sound;
	sf::SoundBuffer* thebuffer = new sf::SoundBuffer;

	thebuffer->loadFromFile(m_directory + path);

	thesound->setBuffer(*thebuffer);

	soundstruct.path = path;
	soundstruct.soundData = thesound;
	soundstruct.buffer = thebuffer;

	m_SoundBank.push_back(soundstruct);
	

}

void SoundManager::AddMusic(std::string path)
{

	MusicStruct musicstruct;
	sf::Music* themusic = new sf::Music;

	themusic->openFromFile(m_directory + path);
	musicstruct.path = path;
	musicstruct.soundHandle = themusic;

	m_MusicBank.push_back(musicstruct);

}
void SoundManager::MuteMusic()
{
	if (b_MuteM)
	{
		SetMusicVolume(OldVolMusic);

		b_MuteM = false;
	}
	else
	{
		OldVolMusic = GetMusicVolume();

		SetMusicVolume(0);
		b_MuteM = true;
	}



}
void SoundManager::MuteSound()
{
	if (b_MuteS)
	{



	}
	else
	{

	}
	SetSoundVolume(0);
}

void SoundManager::StopMusic()
{
	for (MusicStruct music : m_MusicBank)
	{
		music.soundHandle->stop();
	}

}

