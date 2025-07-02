#include "stdafx.h"
#include "SoundGo.h"

SoundGo::SoundGo()
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
	if (id == "Chop")
	{
		soundChop.play();
	}
	if (id == "wave")
	{
		soundWave.play();
	}
	if (id == "spark")
	{
		soundSpark.play();
	}
	if (id == "Death")
	{
		soundDeath.play();
	}
	if (id == "OutOfTime")
	{
		soundOutOfTime.play();
	}
}





