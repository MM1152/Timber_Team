#pragma once
#include "GameObject.h"

class PlayerMuliti : public GameObject
{
protected:
	sf::Keyboard::Key key1;
	sf::Keyboard::Key key2;

	sf::Sprite sprite;
	sf::Sprite axeSprite;
	sf::Sprite elecSprite;
	sf::Sprite waterSprite;


	std::string texId;
	std::string ripId;
	std::string axeId;
	std::string waterId;
	std::string elecId;


	Sides side;

	bool isDie;

	void SetSide(Sides side);
public:
	PlayerMuliti(const std::string& name , sf::Keyboard::Key key1, sf::Keyboard::Key key2, int index);
	~PlayerMuliti() override;

	void SetPosition(const sf::Vector2f& pos);
	void SetRotation(float rot);
	void SetOrigin(const sf::Vector2f& o);
	void SetOrigin(Origins preset);
	void SetScale(const sf::Vector2f& s);
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	Sides GetSide();
	bool CheckDie();
	void Die();
};

