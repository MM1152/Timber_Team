#include "stdafx.h"
#include "Player.h"

Player::Player(const std::string& name)
	: GameObject(name)
{
}

void Player::SetAlive(bool alive)
{
	isAlive = alive;
	if (isAlive)
	{
		sprite.setTexture(TEXTURE_MGR.Get(texPlayerId));
	}
	else
	{
		sprite.setTexture(TEXTURE_MGR.Get(ripTexId));
		sprite.setScale({ 1.f, 1.f });
		drawAxe = false;
		drawElec = false;
	}
	Utils::SetOrigin(sprite, Origins::BC);
}

void Player::SetSide(Sides s)
{
	side = s;

	sprite.setPosition(position + positions[(int)side]);
	sprite.setScale(scales[(int)side]);

	axe.setPosition(position + axePositions[(int)side]);
	axe.setScale(scales[(int)side]);
	elec.setPosition(position + elecPositions[(int)side]);
	elec.setScale(scales[(int)side]);
	water.setPosition(position + waterPositions[(int)side]);
	water.setScale(scales[(int)side]);
}

void Player::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	sprite.setPosition(position + positions[(int)side]);
	axe.setPosition(position + axePositions[(int)side]);
	elec.setPosition(position + elecPositions[(int)side]);
	water.setPosition(position + waterPositions[(int)side]);
}

void Player::Init()
{
	axeTexId = "graphics/axe.png";
	ripTexId = "graphics/rip.png";
	elecTexId = "graphics/electric.png";
	waterTexId = "graphics/water.png";

	positions.resize(2);
	positions[(int)Sides::Left] = { -300.f, 0.f };
	positions[(int)Sides::Right] = { 300.f, 0.f };
	scales.resize(2);
	scales[(int)Sides::Left] = { -1.f, 1.f };
	scales[(int)Sides::Right] = { 1.f, 1.f };

	axePositions.resize(2);
	axePositions[(int)Sides::Left] = { -165.f, -80.f };
	axePositions[(int)Sides::Right] = { 165.f, -80.f };

	elecPositions.resize(2);
	elecPositions[(int)Sides::Left] = { -280.f, -90.f };
	elecPositions[(int)Sides::Right] = { 280.f, -90.f };

	waterPositions.resize(2);
	waterPositions[(int)Sides::Left] = { -0.f, -90.f };
	waterPositions[(int)Sides::Right] = { 0.f, -90.f };
}

void Player::Release()
{
}

void Player::Reset()
{
	int choice = SCENE_MGR.GetChoiceCharacter();
	switch (choice)
	{
	case 0:
		texPlayerId = "graphics/player.png";
		break;
	case 1:
		texPlayerId = "graphics/pikachu.png";
		break;
	case 2:
		texPlayerId = "graphics/turtle.png";
		break;
	}
	sprite.setTexture(TEXTURE_MGR.Get(texPlayerId));
	Utils::SetOrigin(sprite, Origins::BC);

	axe.setTexture(TEXTURE_MGR.Get(axeTexId));
	Utils::SetOrigin(axe, Origins::BC);

	elec.setTexture(TEXTURE_MGR.Get(elecTexId));
	Utils::SetOrigin(elec, Origins::BR);

	water.setTexture(TEXTURE_MGR.Get(waterTexId));
	Utils::SetOrigin(water, Origins::BC);

	SetSide(Sides::Right);
}

void Player::Update(float dt)
{

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);

	if (drawAxe && SCENE_MGR.GetChoiceCharacter() == 0)
	{
		window.draw(axe);
	}
	if (drawElec && SCENE_MGR.GetChoiceCharacter() == 1)
	{
		window.draw(elec);
	}
	if (drawWater && SCENE_MGR.GetChoiceCharacter() == 2)
	{
		window.draw(water);
	}

}