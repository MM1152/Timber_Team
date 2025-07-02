#include "stdafx.h"
#include "PlayerMuliti.h"

void PlayerMuliti::SetSide(Sides side)
{
	this->side = side;

	if (side == Sides::Left) {
		SetScale({ -1 , 1 });
	}
	else if (side == Sides::Right) {
		SetScale({ 1 , 1 });
	}
}

PlayerMuliti::PlayerMuliti(const std::string& name, sf::Keyboard::Key key1, sf::Keyboard::Key key2)
	:GameObject(name)
	, key1(key1)
	, key2(key2)
	, isDie(false)
{
	texId = "graphics/player.png";
	ripId = "graphics/rip.png";
	axeId = "graphics/axe.png";
}

PlayerMuliti::~PlayerMuliti()
{
}

void PlayerMuliti::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	axeSprite.setPosition(position);
	sprite.setPosition(position);
}

void PlayerMuliti::SetRotation(float rot)
{
	rotation = rot;
	sprite.setRotation(rotation);
}

void PlayerMuliti::SetOrigin(const sf::Vector2f& o)
{
	origin = o;
	axeSprite.setOrigin({ origin.x + 120.f, origin.y  - 110.f});
	sprite.setOrigin(origin);
}

void PlayerMuliti::SetOrigin(Origins preset)
{
	originPreset = preset;
	
	if (originPreset != Origins::Custom) {
		Utils::SetOrigin(sprite, originPreset);
	}
}

void PlayerMuliti::SetScale(const sf::Vector2f& s)
{
	scale = s;
	axeSprite.setScale(scale);
	sprite.setScale(scale);
}

void PlayerMuliti::Init()
{
	
}

void PlayerMuliti::Release()
{
}

void PlayerMuliti::Reset()
{
	sprite.setTexture(TEXTURE_MGR.Get(texId));
	axeSprite.setTexture(TEXTURE_MGR.Get(axeId));
}

void PlayerMuliti::Update(float dt)
{
	if (InputMgr::GetKeyDown(key1)) {
		SetSide(Sides::Left);
	}
	if (InputMgr::GetKeyDown(key2)) {
		SetSide(Sides::Right);
	}

}

void PlayerMuliti::Draw(sf::RenderWindow& window)
{
	if (active) {
		window.draw(sprite);
		if (InputMgr::GetKey(key1) || InputMgr::GetKey(key2)) {
			window.draw(axeSprite);
		}
	}
}

Sides PlayerMuliti::GetSide()
{
	return side;
}

bool PlayerMuliti::CheckDie()
{
	return isDie;
}

void PlayerMuliti::Die()
{
	isDie = true;
	sprite.setTexture(TEXTURE_MGR.Get(ripId));
}
