#pragma once
#include "GameObject.h"
class Log : public GameObject
{
protected:
	std::string logIds;
	sf::Sprite spriteLog[5];

	sf::Keyboard::Key key1;
	sf::Keyboard::Key key2;

	sf::Vector2f gravity = { 0.f , 3000.f };
	sf::Vector2f velocity[5];
	float speed = 1000.f;

	sf::Vector2f InitPos = { -100.f , -100.f };
	sf::Vector2f backGroundSize;

	sf::Vector2f windowRange; // 범위 체크용 x = 최소값 , y = 최대값

	bool isActive[5] = {true , true ,true ,true , true};
public:
	Log(sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& id = "", sf::Vector2f windowRange = { 0,(float)FRAMEWORK.GetWindowSize().x }, const std::string& name = "");
	~Log() override = default;
	
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;
	void SetScale(const sf::Vector2f& s) override;

	void CheckOutOfWindow(int idx);
	void SetWindowRange(sf::Vector2f windowRange);
};

