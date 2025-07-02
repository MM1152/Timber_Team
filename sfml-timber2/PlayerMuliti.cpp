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

PlayerMuliti::PlayerMuliti(const std::string& name, sf::Keyboard::Key key1, sf::Keyboard::Key key2, int index)
	:GameObject(name)
	, key1(key1)
	, key2(key2)
	, isDie(false)
{
	switch (index)
	{
	case 0:
		texId = "graphics/player.png";
		break;
	case 1:
		texId = "graphics/pikachu.png";
		break;
	case 2:
		texId = "graphics/turtle.png";
		break;
	}

	ripId = "graphics/rip.png";
	axeId = "graphics/axe.png";
	side = Sides::Right;
	elecId = "graphics/electric.png";
	waterId = "graphics/water.png";
}

PlayerMuliti::~PlayerMuliti()
{
}

void PlayerMuliti::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	axeSprite.setPosition(position);
	sprite.setPosition(position);
	elecSprite.setPosition(position + sf::Vector2f(0.f, -500.f));
	waterSprite.setPosition(position + sf::Vector2f(0.f, -500.f));
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
	elecSprite.setOrigin({ origin.x + 400.f, origin.y - 100.f });
	waterSprite.setOrigin({ origin.x + 500.f, origin.y - 200.f });
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
	elecSprite.setScale(scale);
	waterSprite.setScale(scale);
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
	elecSprite.setTexture(TEXTURE_MGR.Get(elecId));
	waterSprite.setTexture(TEXTURE_MGR.Get(waterId));
}

void PlayerMuliti::Update(float dt)
{
	if (InputMgr::GetKeyDown(key1)) {
		SetSide(Sides::Left);
		bool isKey = (InputMgr::GetKey(key1) || InputMgr::GetKey(key2));

		int choice = (position.x < 960) ? SCENE_MGR.GetChoiceCharacter() : SCENE_MGR.GetChoiceCharacter2p();

		if (isKey && choice == 0)
		{
			SOUND_MGR.Play("Chop");
		}
		if (isKey && choice == 1)
		{
			SOUND_MGR.Play("spark");
		}
		if (isKey && choice == 2)
		{
			SOUND_MGR.Play("wave");
		}
	}
	if (InputMgr::GetKeyDown(key2)) {
		SetSide(Sides::Right);
		bool isKey = (InputMgr::GetKey(key1) || InputMgr::GetKey(key2));

		int choice = (position.x < 960) ? SCENE_MGR.GetChoiceCharacter() : SCENE_MGR.GetChoiceCharacter2p();

		if (isKey && choice == 0)
		{
			SOUND_MGR.Play("Chop");
		}
		if (isKey && choice == 1)
		{
			SOUND_MGR.Play("spark");
		}
		if (isKey && choice == 2)
		{
			SOUND_MGR.Play("wave");
		}
	}

}

void PlayerMuliti::Draw(sf::RenderWindow& window)
{
	if (active) {
		window.draw(sprite);
		bool isKey = (InputMgr::GetKey(key1) || InputMgr::GetKey(key2));


		int choice = (position.x < 960) ? SCENE_MGR.GetChoiceCharacter() : SCENE_MGR.GetChoiceCharacter2p();
	
		if (isKey && choice == 0)
		{
			window.draw(axeSprite);
		}
		if (isKey && choice == 1)
		{
			window.draw(elecSprite);
		}
		if (isKey && choice == 2)
		{
			window.draw(waterSprite);
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
	SOUND_MGR.Play("Death");
}
