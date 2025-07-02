#include "stdafx.h"
#include "Timer.h"

void Timer::Init()
{
}

void Timer::Release()
{
}

void Timer::Reset()
{
	SetScore(0);
	time = 5.f;
	SetValue(time / 5.f);
	timer.setFillColor(sf::Color::Red);
}

void Timer::Update(float dt)
{
}

void Timer::Draw(sf::RenderWindow& window)
{
	if (active) {
		window.draw(timer);
	}
}


void Timer::SetValue(float value)
{
}

float Timer::GetTime(float value)
{
	return 0.0f;
}
