#include "stdafx.h"
#include "Branch.h"

Branch::Branch(const std::string& id, sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& name)
	:GameObject(name)
	, key1(key1)
	, key2(key2)
	,texId(id)
	,scaleX(1)
{
}

void Branch::SetOrigin(const sf::Vector2f& o)
{
	origin = o;
	for (int i = 0; i < BRANCH_SIZE; i++) {
		branchs[i].setOrigin(origin);
	}
}

void Branch::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	for (int i = 0; i < BRANCH_SIZE; i++) {
		branchs[i].setPosition({pos.x , branchs[i].getPosition().y});
	}
}

void Branch::SetScale(const sf::Vector2f& s)
{
	scale = s;
	scaleX = s.x;

	SetSide();
}

void Branch::Init()
{
}

void Branch::Release()
{
}

void Branch::Reset()
{
	for (int i = 0; i < BRANCH_SIZE; i++) {
		branchs[i].setTexture(TEXTURE_MGR.Get(texId));
		branchs[i].setPosition({ branchs[i].getPosition().x , i * 150.f});
		sides[i] = (Sides)Utils::RandomRange(0, 3);
	}
	
	sides[BRANCH_SIZE - 1] = Sides::None;
	SetSide();
}

void Branch::Update(float dt)
{
	if (InputMgr::GetKeyDown(key1) || InputMgr::GetKeyDown(key2)) {
		UpdateBranch();
	}
}


void Branch::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < BRANCH_SIZE; i++) {
		if (sides[i] != Sides::None) {
			window.draw(branchs[i]);
		}
 	}
}

void Branch::SetSide()
{
	for (int i = 0; i < BRANCH_SIZE; i++) {
		if (sides[i] == Sides::Left) {
			branchs[i].setScale({ -(scaleX), branchs[i].getScale().y });
		}
		else if (sides[i] == Sides::Right) {
			branchs[i].setScale({ scaleX, branchs[i].getScale().y });
		}
	}
}

void Branch::UpdateBranch()
{
	for (int i = BRANCH_SIZE - 1; i > 0; i--) {
		sides[i] = sides[i-1];
	}
	sides[0] = (Sides)Utils::RandomRange(0, 3);
	SetSide();
}

Sides Branch::GetSide()
{
	return sides[BRANCH_SIZE - 1];
}
