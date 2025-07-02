#include "stdafx.h"
#include "DummyLog.h"
#include "Log.h"

DummyLog::DummyLog(sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& id, sf::Vector2f dummyRange, const std::string& name)
	:Log(key1, key2, id, dummyRange, name)
{

}

void DummyLog::Init()
{
	for (int i = 0; i < 5; i++)
	{
		dummyLog->position = spriteLog[i].getPosition();
	}
	
	dummyLog->setOrigin()

}
void DummyLog::Release()
{

}
void DummyLog::Reset()
{

}
void DummyLog::Update(float dt)
{

}
void DummyLog::Draw(sf::RenderWindow& window)
{

}
void DummyLog::SetPosition(sf::Vector2f& pos)
{
	
}

void DummyLog::SetOrigin(Origins preset)
{ 

}
void DummyLog::SetScale(const sf::Vector2f& s)
{

}
void DummyLog::CheckOutOfWindow(int idx)
{

} 
void DummyLog::SetDummyRange(sf::Vector2f dummyRange)
{

}

