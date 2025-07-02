#include "stdafx.h"
#include "DummyLog.h"
#include "Log.h"

DummyLog::DummyLog(sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& id, sf::Vector2f dummyRange, const std::string& name)
	:Log(key1, key2, id, dummyRange, name)
{

}
DummyLog::DummyLog(sf::Vector2f dummyRange)
	:Log(dummyRange)
{

}

void DummyLog::Init()
{
	for (int i = 0; i < 5; i++)
	{
		position[i] = spriteLog[i].getPosition();
		dummyLog[i].setTexture(TEXTURE_MGR.Get(logIds));
	}
	DummyLog DummyLog({(float)FRAMEWORK.GetWindowSize().x, 200.f});
	//AddGameObject(log);
	//Scene::Enter();
	//log->SetPosition({ tree->GetPosition().x , (float)TEXTURE_MGR.Get("graphics/tree.png").getSize().y });
	//log->SetOrigin(Origins::BC);
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

