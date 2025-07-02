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
	time = 5.f;
	SetValue(time / 5.f);
	timer.setFillColor(sf::Color::Red);
	SetOrigin(Origins::TL);
}

void Timer::Update(float dt)
{
	time -= dt;
	SetValue(time / 5.f);
}

void Timer::Draw(sf::RenderWindow& window)
{
	if (active) {
		window.draw(timer);
	}
}

void Timer::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom) {
		Utils::SetOrigin(timer, originPreset);
	}
}

void Timer::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	timer.setPosition(pos);
}


void Timer::SetValue(float value)
{
	timer.setSize({timerSize.x * value , timerSize.y});
}

float Timer::GetTime()
{
	return time;
}
