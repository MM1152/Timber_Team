#pragma once
#include "stdafx.h"
#include "GameObject.h"
class Item : public GameObject
{
protected:
	sf::Sprite sp;
	std::string texId;

	sf::Vector2f dropSpeed = { 0.f , 500.f };

	Sides side;
public:
	Item(const std::string& id , const std::string& name);
	~Item() override = default;
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	
	void SetPosition(const sf::Vector2f& pos) override; 
	void SetOrigin(const sf::Vector2f& o) override;
	bool CheckOutOfWindow();
	void SetSide(Sides side);
	Sides GetSide() const { return side; };
	void Spawn();

	virtual void UseItem() = 0;
};

