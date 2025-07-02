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
	bufferDeath.loadFromFile("sound/death.wav");
	bufferOutOfTime.loadFromFile("sound/out_of_time.wav");

	soundChop.setBuffer(bufferChop);
	soundDeath.setBuffer(bufferDeath);
	soundOutOfTime.setBuffer(bufferOutOfTime);
}

void SoundGo::Play(std::string id)
{
	if (id == "chop")
	{
		soundChop.play();
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





