#include "stdafx.h"
#include "Item.h"

Item::Item(const std::string& id, const std::string& name)
	:texId(id)
	,GameObject(name)
{
	
}

void Item::Init()
{

}

void Item::Release()
{

}

void Item::Reset()
{
	//Spawn();
	sp.setTexture(TEXTURE_MGR.Get(texId));
	Spawn();
}

void Item::Update(float dt)
{
	sf::Vector2f pos = sp.getPosition();
	pos += dropSpeed * dt;
	SetPosition(pos);

	if (CheckOutOfWindow()) {
		Spawn();
	}
}

void Item::Draw(sf::RenderWindow& window)
{
	if (side != Sides::None) {
		window.draw(sp);
	}
}

void Item::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sp.setPosition(position);
}

void Item::SetOrigin(const sf::Vector2f& o)
{
	origin = o;
	sp.setOrigin(o);
}

bool Item::CheckOutOfWindow()
{
	if (sp.getPosition().y >= FRAMEWORK.GetWindowSize().y + 100) {
		std::cout << "Out Item" << std::endl;
		return true;
	}
	return false;
}

void Item::SetSide(Sides side)
{
	this->side = side;
	
	if (this->side == Sides::Right) {
		sp.setScale({1,1});
	}
	else if (this->side == Sides::Left) {
		sp.setScale({ -1 , 1});
	}
	else {
		sp.setScale({ 0, 0 });
	}
}

void Item::Spawn()
{
	SetPosition({ sp.getPosition().x , 0});
	float spawn = Utils::RandomValue();
	if (spawn <= 0.6) {
		SetSide(Sides::None);
	}
	else {
		SetSide((Sides)Utils::RandomRange(0, 2));
	}
}
