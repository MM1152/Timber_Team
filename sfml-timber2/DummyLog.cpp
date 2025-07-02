#include "stdafx.h"
#include "DummyLog.h"
#include "Log.h"

DummyLog::DummyLog(sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& id, sf::Vector2f dummyRange, const std::string& name)
	:Log(key1, key2, id, dummyRange, name)
{

}

void DummyLog::Init()
{
	for (int i = 0; i < 5; i++)//@
	{
		//position[i] = spriteLog[i].getPosition();
		//dummyLog[i].setTexture(TEXTURE_MGR.Get(logIds));
	}	
}

void DummyLog::Release()
{
	
}

void DummyLog::Reset()
{

}

void DummyLog::Update(float dt)
{
	for (int i = 0; i < 5; i++)
	{
		//sf::Vector2f pos = dummyLog[i].getPosition();
	}
}

void DummyLog::Draw(sf::RenderWindow& window)
{

}
void DummyLog::SetPosition(const sf::Vector2f& pos)
{
	for (int i = 0; i < 5; i++)
	{
		//position[i] = pos;
		//dummyLog[i].setPosition(position[i]);
	}
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

//log->SetPosition({ tree1->GetPosition().x , tree1->GetSprite().getLocalBounds().height});

//sf::Vector2f pos = spriteLog[i].getPosition();
//velocity[i] += gravity * dt;
//pos += velocity[i] * dt;
//spriteLog[i].setPosition(pos);
//CheckOutOfWindow(i);