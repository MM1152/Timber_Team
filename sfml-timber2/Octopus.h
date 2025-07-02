#pragma once
#include "Item.h"
#include "PlayerMuliti.h"
class Octopus : public Item
{
private:
	sf::Vector2f inkPos;
	sf::Sprite inkText;
	std::string inkTexId;
	PlayerMuliti* const player;
	bool useItem;
	float timer;
	
public:
	Octopus(const std::string& id, const std::string& name , PlayerMuliti* const myPlayer);
	~Octopus() override = default;
	// Item을(를) 통해 상속됨

	void Update(float dt) override;
	void Reset() override;
	void UseItem() override;
	void Draw(sf::RenderWindow& window) override;
	void Setting(sf::Vector2f pos);
};

