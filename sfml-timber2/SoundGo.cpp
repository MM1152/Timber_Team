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
	bufferSpark.loadFromFile("sound/spark.mp3");
	bufferWave.loadFromFile("sound/wave.mp3");
	bufferDeath.loadFromFile("sound/death.wav");
	bufferOutOfTime.loadFromFile("sound/out_of_time.wav");

	soundChop.setBuffer(bufferChop);
	soundSpark.setBuffer(bufferSpark);
	soundWave.setBuffer(bufferWave);
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
	if (id == "spark" && soundMute) {
		soundSpark.play();
	}
	if (id == "wave" && soundMute) {
		soundWave.play();
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