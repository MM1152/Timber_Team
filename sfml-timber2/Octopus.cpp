#include "stdafx.h"
#include "Octopus.h"


void Octopus::Reset()
{
	std::cout << "Ink Reset" << std::endl;
	inkText.setTexture(TEXTURE_MGR.Get(inkTexId));
	inkText.setColor(sf::Color::Black);
	useItem = false;
	Item::Reset();
}

void Octopus::UseItem()
{
	if (side != Sides::None) {
		std::cout << "Use Item" << std::endl;
		useItem = true;
		timer = 2;
	}
}

void Octopus::Update(float dt) {
	Item::Update(dt);

	if (useItem) {
		timer -= dt;
		if (timer <= 0) {
			std::cout << "End Item" << std::endl;
			useItem = false;
		}
		inkText.setColor(sf::Color({ 0 , 0, 0, (sf::Uint8)(255 * (timer / 2.0f)) }));
	}
	if (player->GetSide() == GetSide() && abs(player->GetPosition().y - GetPosition().y) <= 40) {
		UseItem();
		Spawn();
	}
}

void Octopus::Draw(sf::RenderWindow& window)
{
	Item::Draw(window);
	if (useItem) {
		window.draw(inkText);
	}
}

void Octopus::Setting(sf::Vector2f pos)
{
	inkPos = pos;
	inkText.setPosition(inkPos);
}

Octopus::Octopus(const std::string& id, const std::string& name , PlayerMuliti* const myPlayer)
	:Item(id , name)
	,useItem(false)
	, player(myPlayer)
{
	inkTexId = "graphics/indiaink.png";
}
