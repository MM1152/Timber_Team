#include "stdafx.h"
#include "SoundGo.h"

SoundGo::SoundGo()
	:soundMute(true), currentMuteCheck(false)
{
}

SoundGo::~SoundGo()
{
}

void SoundGo::Init()
{
	bufferChop.loadFromFile("sound/chop.wav");
	bufferDeath.loadFromFile("sound/death.wav");
	bufferOutOfTime.loadFromFile("sound/out_of_time.wav");

	soundChop.setBuffer(bufferChop);
	soundDeath.setBuffer(bufferDeath);
	soundOutOfTime.setBuffer(bufferOutOfTime);
}

void SoundGo::Play(std::string id)
{
	if (id == "Chop" && soundMute)
	{
		soundChop.play();
	}
	if (id == "Death" && soundMute)
	{
		soundDeath.play();
	}
	if (id == "OutOfTime" && soundMute)
	{
		soundOutOfTime.play();
	}
}

void SoundGo::MuteSet(bool mute)
{
	soundMute = mute;
}

bool SoundGo::MuteGet()
{
	return soundMute;
}