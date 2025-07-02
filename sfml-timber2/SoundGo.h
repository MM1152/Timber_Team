#pragma once
#include "stdafx.h"

class SoundGo :
	public Singleton<SoundGo>
{
protected:
	std::string soundId;

	sf::SoundBuffer bufferChop;
	sf::SoundBuffer bufferDeath;
	sf::SoundBuffer bufferOutOfTime;

	sf::Sound soundChop;
	sf::Sound soundDeath;
	sf::Sound soundOutOfTime;
	//sprite.setTexture(TEXTURE_MGR.Get(textureId));
public:
	SoundGo();
	~SoundGo();

	void Init();
	void Play(std::string id);
};

#define SOUND_MGR (SoundGo::Instance())
