#pragma once
#include "stdafx.h"
#include "UiHud.h"

class SoundGo :
	public Singleton<SoundGo>
{
protected:
	std::string soundId;

	sf::SoundBuffer bufferChop;
	sf::SoundBuffer bufferSpark;
	sf::SoundBuffer bufferWave;
	sf::SoundBuffer bufferDeath;
	sf::SoundBuffer bufferOutOfTime;

	sf::Sound soundChop;
	sf::Sound soundSpark;
	sf::Sound soundWave;
	sf::Sound soundDeath;
	sf::Sound soundOutOfTime;

	bool soundMute;//@ comment: ¼Ò¸® ²ô±â ¿ë
	bool currentMuteCheck;

	//sprite.setTexture(TEXTURE_MGR.Get(textureId));
public:
	SoundGo();
	~SoundGo();

	void Init();
	void Play(std::string id);
	void MuteSet(bool mute);
	bool MuteGet();
};

#define SOUND_MGR (SoundGo::Instance())
