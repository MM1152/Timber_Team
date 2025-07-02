#pragma once
#include "Log.h"
class DummyLog :
    public Log
{
protected:
	sf::Sprite dummyLog[5];
	sf::Vector2f position[5];
	

public:
    DummyLog(sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& id, sf::Vector2f dummyRange, const std::string& name);
	DummyLog(sf::Vector2f dummyRange);
    ~DummyLog()override = default;

	// GameObject을(를) 통해 상속됨
	void Init();
	void Release();
	void Reset();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	void SetPosition(sf::Vector2f& pos);
	void SetOrigin(Origins preset);
	void SetScale(const sf::Vector2f& s);

	void CheckOutOfWindow(int idx);
	void SetDummyRange(sf::Vector2f dummyRange);
   
};

